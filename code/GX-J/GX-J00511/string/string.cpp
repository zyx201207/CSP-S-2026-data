#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long L = 0;
    long long a[101];
    string b[101];
    string s;
    cin >> n;
    for (long long i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
        L += a[i];
        for (long long j = 1;j <= a[i];j++){
            s += b[i];
        }
    }
    long long l = 0,r = L-1;
    long long cnt = 0;
    while(true){
        if (l >= r){
            break;
        }
        if(s[l] != s[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt;
    return 0;
}
