#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
long long ans=1e18;
vector<long long> g[1000006];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<n;i++){
            cin >> u >> v;
            ans=min(ans,abs(u-v));
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cout << ans << '\n';
    }
    return 0;
}
