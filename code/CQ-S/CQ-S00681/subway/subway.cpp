#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
const int maxm=5e2+5;
const ll inf=1e18;
ll val[maxm][maxm],w[maxn];
vector<pair<int,ll>> t[maxn];
int c,n,m,d,q,cnt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;cnt=m;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,v;cin>>a>>v;
            t[a].push_back({cnt+i,v});
            t[cnt+i].push_back({a,v});
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) val[i][j]=inf;
    for(int i=1;i<=n;i++) val[i][i]=0;
    for(int i=1;i<=m;i++){
        int len=t[i].size();
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                int u=t[i][j].first,v=t[i][k].first;
                if(u==v) continue;
                u-=m,v-=m;
                val[u][v]=min(val[u][v],t[i][j].second+t[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
    while(q--){
        int x,y;cin>>x>>y;
        ll ans=inf;
        int lenx=t[x].size(),leny=t[y].size();
        for(int i=0;i<lenx;i++)
            for(int j=0;j<leny;j++){
                int u=t[x][i].first,v=t[y][j].first;
                u-=m,v-=m;
                ans=min(ans,val[u][v]+t[x][i].second+t[y][j].second);
            }
        cout<<ans+w[x]+w[y]<<"\n";    
    }
    return 0;
}