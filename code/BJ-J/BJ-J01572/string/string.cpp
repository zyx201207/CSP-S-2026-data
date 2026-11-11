#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.out", "w", stdout);
    freopen("string.in", "r", stdin);
    long long n, cnt = 0, q = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n;i++){
        int x;
        char t;
        cin >> x >>t;
        q += x;
        for(int j = 0;j < x;j++){
            s += t;
        }
    }
    for(int i = 0;i * 2 <= q;i++){
        if(s[i] != s[q-1-i]) cnt++;
    }
    cout << cnt;
    return 0;
}

