#include <bits/stdc++.h>
using namespace std;
long long n, a[300000], ans;
char c[300000];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    long long x = 1, y = n;
    while(x < y){
        if(c[x] == c[y]){
            long long t = min(a[x], a[y]);
            a[x] -= t, a[y] -= t;
            x += (a[x] == 0 ? 1 : 0), y -= (a[y] == 0 ? 1 : 0);
        }
        else{
            long long t = min(a[x], a[y]);
            a[x] -= t, a[y] -= t, ans += t;
            x += (a[x] == 0 ? 1 : 0), y -= (a[y] == 0 ? 1 : 0);
        }
    }
    cout << ans;
    return 0;
}

