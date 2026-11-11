#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, a, l, ans=0;
    char c, str[1000000], e, ee;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a >> c;
        for(int j=0; j<a; j++) str[l++] = c;
    }
    for(int i=0; i<l; i++) if(str[i] != str[l-i-1]) ans++;
    cout << ans/2;
    return 0;
}