#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+5;
int C,n,m,D,Q,W[M];
unordered_map<int,int> t[N];     // t[i][j] -> ting j to tai i
vector<int> a[M];   // a[i]={} -> ting i to {}
int g[N][N],dist[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++) cin>>W[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,tmp,u;j<=k;j++){
            cin>>u;
            cin>>tmp;
            t[i][u]=tmp;
            a[u].push_back(i);
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) if(i!=j) g[i][j]=1e18;
    for(int p=1;p<=m;p++){
        for(int i=0;i<a[p].size();i++){
            for(int j=i+1;j<a[p].size();j++){
                int u=a[p][i],v=a[p][j];
                if(t[u].count(p)==0||t[v].count(p)==0) continue;
                g[u][v]=g[v][u]=min(g[u][v],t[u][p]+t[v][p]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(g[i][j]==1e18?-1:g[i][j])<<' ';
        }cout<<endl;
    }*/
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) dist[i][j]=g[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(dist[i][j]==1e18?-1:dist[i][j])<<' ';
        }cout<<endl;
    }*/
    int x,y,ans=1e18;
    while(Q--){
        ans=1e18;
        cin>>x>>y;
        for(int S:a[x]){
            for(int T:a[y]){
                //cout<<S<<' '<<T<<endl;
                ans=min(ans,W[x]+W[y]+t[S][x]+t[T][y]+dist[S][T]);
            }
        }
    cout<<ans<<'\n';
    }
    return 0;
}
