#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt,ans = LLONG_MAX;
ll a[200010],vis[200010];
ll dfs(ll x,ll y){
    if(y == m + 1){
        ll dfsans = -1e9;
        for(ll i = 1;i<= m;i++){
            if(vis[i] == 1 && dfsans == -1e9){
                dfsans = a[i];
            }else{
                dfsans = dfsans^a[i];
                ans = min(ans,dfsans);
            }
        }
        return ans;
    }
    vis[x] = 1;
    return dfs(x+1,y+1);
    vis[x] = 0;
    return dfs(x+1,y+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(ll i = 1;i<=n;i++) cin >> a[i];
    cout << dfs(1,1);
    return 0;
}
