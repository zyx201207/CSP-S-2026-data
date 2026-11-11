#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1145,M=5e5+325;
vector<int> G[M];
int c,n,m,d,q,w[M],dis[M],f[N][N],t0;
bool vis[M],flagt=1,flagk=1;
queue<int> Q;
void add(int u,int v,int w){
    G[u].push_back(v);
    G[v].push_back(u);
    f[u][v]=f[v][u]=w;
}
int solvet(int s,int t){
    for(int i=1;i<=n+m;i++) dis[i]=1e18,vis[i]=0;
    dis[s]=0;
    Q.push(s);vis[s]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int v:G[u]){
            dis[v]=min(dis[v],dis[u]+t0);
            if(!vis[v]){
                Q.push(v);
                vis[v]=1;
            }
        }
    }
    return dis[t];
}
void solve(int r)
{
    for(int i=1;i<=r;i++)
        for(int j=1;j<=r;j++)
            if(!f[i][j]) f[i][j]=1e18;
    for(int k=1;k<=r;k++)
        for(int i=1;i<=r;i++)
            for(int j=1;j<=r;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    if(n>2){
        if(m<=500){
            for(int i=1;i<=n;i++){
                int k;cin>>k;
                if(k>2){
                    flagk=0;
                    for(int j=1;j<=k;j++){
                        int a,t;cin>>a>>t;
                        f[a][i+m]=f[i+m][a]=t;
                    }
                }
                else{
                    int a1,t1,a2,t2;
                    cin>>a1>>t1>>a2>>t2;
                    f[a1][a2]=f[a2][a1]=t1+t2;
                }
            }
            if(flagk) solve(m);
            else solve(m+n);
            while(q--){
                int s,t;
                cin>>s>>t;
                cout<<f[s][t]+w[s]+w[t]<<'\n';
            }
        }
        else{
            for(int i=1;i<=n;i++){
                int k;cin>>k;
                while(k--){
                    int a;cin>>a>>t0;
                    G[a].push_back(i+m);
                    G[i+m].push_back(a);
                }
            }
            while(q--){
                int s,t;
                cin>>s>>t;
                cout<<solvet(s,t)+w[s]+w[t]<<'\n';
            }
        }
    }
    else{
        if(n==1){
            int k;cin>>k;
            for(int i=1;i<=m;i++){
                int x;cin>>x>>f[x][1];
            }
            while(q--){
                int s,t;cin>>s>>t;
                cout<<f[s][1]+f[t][1]+w[s]+w[t]<<'\n';
            }
        }
        else{
            for(int i=1;i<=2;i++){
                int k;cin>>k;
                while(k--){
                    int a;
                    cin>>a;
                    cin>>f[a][i];
                }
            }
            int min_=1e18;
            for(int i=1;i<=m;i++){
                if(!f[i][1]) f[i][1]=1e18;
                if(!f[i][2]) f[i][2]=1e18;
            }
            for(int i=1;i<=n;i++) min_=min(f[i][1]+f[i][2],min_);
            while(q--)
            {
                int s,t;cin>>s>>t;
                cout<<min(min(f[s][1]+f[t][1],f[s][2]+f[t][2]),min(f[s][1]+f[t][2],f[t][1]+f[s][2])+min_)+w[s]+w[t]<<'\n';
            }
        }
    }
    return 0;
}
