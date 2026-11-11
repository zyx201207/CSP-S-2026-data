#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=507,M=5e5+7;
const ll inf=1e18;
int c,n,m,d,q;
ll w[M];
struct edge{
    ll v;
    int pid;
};
vector<edge>g[M];
ll f[N][N];
inline void chkmn(ll &a,ll b){
    a=min(a,b);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[a].emplace_back((edge){t,i});
        }   
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)f[i][j]=f[j][i]=inf;
    for(int i=1;i<=m;i++){
        int len=g[i].size();
        for(int j=0;j<len;j++){
            for(int k=j+1;k<len;k++){
                ll elen=g[i][j].v+g[i][k].v;
                chkmn(f[g[i][j].pid][g[i][k].pid],elen);
                chkmn(f[g[i][k].pid][g[i][j].pid],elen);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(edge pp:g[x])
            for(edge qq:g[y])
                ans=min(ans,w[x]+w[y]+pp.v+qq.v+f[pp.pid][qq.pid]);
        cout<<ans<<'\n';
    }
    return 0;
}