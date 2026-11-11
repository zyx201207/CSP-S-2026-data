#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
const ll N=500005;
ll n,m,a[N],tmp[N],ansarr[N],ans=0xFFFFFFFFFFFFFFFF;
bool vis[N]={false};
int dfs(int crystal, int addcnt) {
    if(crystal == n + 1){
        for(ll i=1;i<=n;i++){
            ansarr[tmp[i]]++;
        }
        for(ll i=1;i<=n;i++){
            ans = max(ans, ansarr[i]);
        }
    }
    for(ll i=crystal;i<=n;i++){
        vis[i] = true;
        dfs(crystal + 1, addcnt);
        if(addcnt < m){
            tmp[i]++;
            dfs(crystal + 1, addcnt + 1);
        }
    }
    return 0;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        tmp[i] = a[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
