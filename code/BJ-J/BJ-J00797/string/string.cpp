#include<bits/stdc++.h>
using namespace std;
int n, a[200005];
char c[200005];
long long ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    int l = 1, r = n;
    while(l < r){
        int m = min(a[l], a[r]);
        if(c[l] != c[r]) ans += 1ll * m;
        a[l] -= m, a[r] -= m;
        if(!a[l]) l++;
        if(!a[r]) r--;
    }
    printf("%lld", ans);
}
