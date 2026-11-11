#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
struct Node{
    long long mem;
    char zi;
}a[M];
long long n, tt;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> a[i].mem >> a[i].zi;
    }
    long long left = 1, right = n;
    while(left < right){
        if(a[left].zi == a[right].zi){
            if(a[left].mem < a[right].mem){
                a[right].mem -= a[left].mem;
                left++;
            }
            else if(a[left].mem > a[right].mem){
                a[left].mem -= a[right].mem;
                right--;
            }
            else{
                left++;
                right--;
            }
        }
        else{
            if(a[left].mem < a[right].mem){
                a[right].mem -= a[left].mem;
                tt += a[left].mem;
                left++;
            }
            else if(a[left].mem > a[right].mem){
                a[left].mem -= a[right].mem;
                tt += a[right].mem;
                right--;
            }
            else{
                tt += a[right].mem;
                left++;
                right--;
            }
        }
    }
    cout << tt;
    return 0;
}