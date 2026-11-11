#include<bits/stdc++.h>
using namespace std;
const int M=500005,N=505;
int c,n,m,d,q;
int w[M],k[N];
int a[N][M],t[N][M];
int x,y;

vector<pair<int,int> >g[M];

void add_edge(int u,int v,int w){
    g[u].push_back(pair<int,int>(v,w));
    g[v].push_back(pair<int,int>(u,w));
}

bool vis[N+M];
int ans=-1;

void dfs(int u,int v,int s){
    if(u==v){
        if(ans==-1)ans=s;
        else ans=min(ans,s);
        return;
    }
    vis[u]=1;
    for(auto nx:g[u]){
        if(!vis[nx.first]){
            vis[nx.first]=1;
            dfs(nx.first,v,s+nx.second);
            vis[nx.first]=0;
        }
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int nd=m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            add_edge(a[i][j],nd+1,t[i][j]);
        }
        nd++;
    }
//    cout<<"total "<<nd<<" nodes\n";
    for(int i=1;i<=nd;i++){
        for(auto node:g[i]){
//            cout<<i<<"->"<<node.first<<":"<<node.second<<"    ";
        }
//        cout<<'\n';
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=-1;
        for(int i=0;i<N+M;i++){
            vis[i]=0;
        }
        dfs(x,y,0);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}