#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
const int M=1e4+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct edge{int id;ll x;};
struct node{int v;ll w;};
int c,n,m,d,q;
int w[N],a[N],t[N];
int id[N],tot;
ll f[M][M];
vector<edge> e[N];
vector<node> g[N<<1];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    tot=m;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            if(id[a[j]]==0) id[a[j]]=a[j];
            else id[a[j]]=++tot;
            e[a[j]].push_back({id[a[j]],t[j]});
        }
        for(int l=1;l<=k;l++){
            for(int r=l+1;r<=k;r++){
                g[id[a[r]]].push_back({id[a[l]],t[l]});
                g[id[a[l]]].push_back({id[a[r]],t[r]});
            }
        }
    }
    for(int i=1;i<=tot;i++){
        if(e[i].size()>1){
            for(auto l:e[i]){
                for(auto r:e[i]){
                    if(l.id==r.id) continue;
                    g[l.id].push_back({r.id,r.x});
                }
            }
        }
    }
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=tot;j++)
            if(i!=j) f[i][j]=INF;
    for(int i=1;i<=tot;i++)
        for(auto j:g[i]) f[i][j.v]=j.w;
    for(int k=1;k<=tot;k++)
        for(int i=1;i<=tot;i++)
            for(int j=1;j<=tot;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y; cin>>x>>y;
        ll ans=INF;
        for(auto i:e[x])
            for(auto j:e[y]) ans=min(ans,i.x+f[i.id][j.id]);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}