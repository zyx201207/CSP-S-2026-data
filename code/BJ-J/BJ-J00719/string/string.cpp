#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[1000000],b = 0,d = 0;
    string s;
    char c;
    cin >> n;
    for(long long i = 0; i < n; i ++){
        cin >> a[i];
        cin >> c;
        for(long long j = 0; j < a[i]; j ++){
            s[d] = c;
            d ++;
        }
    }
    for(long long i = 0; i < n / 2; i ++){
        if(s[i] != s[n - i - 1]){
            s[i] = s[n - i];
            b ++;
        }
    }
    cout << b;
}