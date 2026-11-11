#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,a[1000000],b = 0;
    cin >> n >> m;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(long long i = 0; i < n; i ++){
        for(long long j = 0; j < i; j ++){
            if (b < (a[i] & a[j])) b = a[i] & a[j];
        }
    }
    cout << b;
}//嗯不会写了就这样吧 :<