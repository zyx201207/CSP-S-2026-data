//Change's Code
#include <bits/stdc++.h>
#define int long long
using namespace std;
// const int MAXA = (int)(1e18) + (int)(1e12);
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> sz(n+1);
    for(int i=1;i<=n;i++){
        cin >> sz[i];
    }
    sort(sz.begin()+1, sz.begin()+1+n);
    int l = 1, ans = 0, he = 0;
    using i128 = __int128;
    for(int r=1;r<=n;r++){
        he += sz[r];
        while(l < r && (i128)sz[r] * (r-l+1) - he > m){
            he -= sz[l++];
        }
        ans = max(ans, r-l+1);
    }
    printf("%lld\n", ans);
    return 0;
}
//AC