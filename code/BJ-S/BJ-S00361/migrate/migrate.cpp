#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--){
        ll n,d;
        cin>>n>>d;
        vector<ll> x(n+1);
        for (int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll ans=0;
        for (int i=1;i<=n;i++){
            vector<ll> dist(n+1,INF);
            queue<ll> q;
            vector<ll> res(n+1,0);
            q.push(i);
            dist[i]=0;
            res[i]=1;
            while (!q.empty()){
                ll u=q.front();
                q.pop();
                for (int v=u+1;v<=n;v++){
                    if (x[v]-x[u]>d){
                        continue;
                    }
                    if (dist[v]>dist[u]+1){
                        dist[v]=dist[u]+1;
                        res[v]=res[u];
                        q.push(v);
                    }
                    else if (dist[v]==dist[u]+1){
                        res[v]+=res[u];
                        q.push(v);
                    }
                }
            }
            for (int j=i+1;j<=n;j++){
                if (res[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}