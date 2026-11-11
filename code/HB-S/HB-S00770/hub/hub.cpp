#include <bits/stdc++.h>
using namespace std;
int n,k;
int fun(int m,int n){
    int a = 1,b = 1;
    for(int i = m;i >= m-n+1;i--){
        a *= i;
    }
    for(int j = n;j >= 1;j--){
        b *= j;
    }
    cout << a/b;
}
int main(){
    int c,t;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        fun(n,k);
    }
    return 0;
}
