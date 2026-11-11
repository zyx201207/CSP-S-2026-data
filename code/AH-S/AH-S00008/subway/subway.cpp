#include<bits/stdc++.h>
#define int long long
#define pii pair<long long,long long>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,k[N],w[M],e[N][N],f[N][N];
vector<pii> a[M];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++){
            cin>>x>>y;
            a[x].push_back({i,y});
        }
    }
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=0;k<a[i].size();k++){
                int u=a[i][j].first,v=a[i][k].first;
                e[u][v]=e[v][u]=min(e[u][v],a[i][j].second+a[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                f[i][j]=0;
                continue;
            }
            f[i][j]=e[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int k=1;k<=q;k++){
        int x,y;
        cin>>x>>y;
        int ans=0x3f3f3f3f3f3f3f3f3f;
        for(int i=0;i<a[x].size();i++){
            for(int j=0;j<a[y].size();j++){
                int u=a[x][i].first,v=a[y][j].first;
                ans=min(ans,w[x]+w[y]+a[x][i].second+a[y][j].second+f[u][v]);
            }
        }
        cout<<ans<<"\n";
    }
}
