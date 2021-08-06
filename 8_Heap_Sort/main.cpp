//
//  main.cpp
//  8_Heap_Sort
//
//  Created by 세광 on 2021/08/06.
//

#include <iostream>

using namespace std;

class HeapSort {
public:
    HeapSort();
    ~HeapSort();
    
    void Ascending();
    void Decending();
    void Print();
    
private:
    int n;
    int *arr;
};

int main() {
    HeapSort *sort = new HeapSort;
    sort->Ascending();
    sort->Print();
    sort->Decending();
    sort->Print();
    delete sort;
}

HeapSort::HeapSort() {
    cin >> n;
    arr = new int[n];
    for (size_t i = 0; i < n; i++) cin >> arr[i];
}

HeapSort::~HeapSort() {
    delete [] arr;
    arr = NULL;
}

void HeapSort::Ascending() {
    for (int i = 1; i < n; i++) { // 힙을 구성
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (arr[root] < arr[c]) {
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (int i = n - 1; i >= 0; i--) { // 크기를 줄여가며 반복적으로 힙을 구성
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            if (c < i - 1 && arr[c] < arr[c + 1]) c++;
            if (c < i && arr[root] < arr[c]) {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            root = c;
        } while (c < i);
    }
}

void HeapSort::Decending() {
    for (int i = 1; i < n; i++) { // 힙을 구성
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (arr[root] > arr[c]) {
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (int i = n - 1; i >= 0; i--) { // 크기를 줄여가며 반복적으로 힙을 구성
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            if (c < i - 1 && arr[c] > arr[c + 1]) c++;
            if (c < i && arr[root] > arr[c]) {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            root = c;
        } while (c < i);
    }
}

void HeapSort::Print() {
    for (size_t i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
}
