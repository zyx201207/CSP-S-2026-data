#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int n, a[N], L = 0, ans;
char c[N];
string s;

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        L += a[i];
        while(a[i]--) s += c[i];
    }
    s = ' ' + s;
    int mid = 0;
    if(L % 2 == 0) mid = L / 2;
    else mid = L / 2 + 1;
    for(int i = 1; i <= mid; i++){
        if(s[i] != s[L + 1 - i]) ans++;
    }
    cout << ans;
    return 0;
}

