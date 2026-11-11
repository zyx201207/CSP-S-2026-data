#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
const ll MAXN=5e5+55;
ll testid,n,m,d,q,x,y,k,a,t,ans;
ll ap[MAXN],dist[505][505];
vector<pll> adj[MAXN];//left->right
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // double time1=clock();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>testid>>n>>m>>d>>q;
    memset(dist,0x3f,sizeof(dist));
    for(ll i=1;i<=m;i++) cin>>ap[i];
    for(ll i=1;i<=n;i++){
        dist[i][i]=0;
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a>>t;
            adj[a].push_back(mkp(i,t));
        }
    }
    for(ll i=1;i<=m;i++) for(auto &u:adj[i]) for(auto &v:adj[i]) dist[u.fi][v.fi]=min(u.se+v.se,dist[u.fi][v.fi]);
    for(ll k=1;k<=n;k++) for(ll i=1;i<=n;i++) for(ll j=1;j<=n;j++) dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
    while(q--){
        cin>>x>>y;
        ans=4e18;
        for(auto &i:adj[x]) for(auto &j:adj[y]) ans=min(ap[x]+ap[y]+i.se+j.se+dist[i.fi][j.fi],ans);
        cout<<ans<<'\n';
    }
    // double time2=clock();
    // cout<<(time2-time1)/CLOCKS_PER_SEC;
    return 0;
}