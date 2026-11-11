#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;

int c,n,m,d,q,w[maxn],k[maxn],a[505][maxn],t[505][maxn],x,y,ans=1e9;
bool vis[maxn];
void dfs(int now,int cnt,int xian){
    for(int j=1;j<=k[xian];j++){
        int v=a[xian][j];
        if(v==y){
            cnt+=t[xian][j];
            ans=min(ans,cnt);
            return;
        }
    }
    for(int j=1;j<=k[xian];j++){
        int v=a[xian][j];
        if(!vis[v]){
            for(int ii=1;ii<=n;ii++){
                if(ii==xian) continue;
                for(int jj=1;jj<=k[ii];jj++){
                    int vv=a[ii][jj];
                    if(vv==v){
                        dfs(v,cnt+t[xian][j]+t[ii][jj],ii);
                    }
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        ans=1e9;
        memset(vis,0,sizeof(vis));
        cin>>x>>y;
        vis[x]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    dfs(x,w[x]+w[y]+t[i][j],i);
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

