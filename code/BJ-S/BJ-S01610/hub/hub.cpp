#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

const int maxn=2e6+5;

int c,t,n,k;
vector<int>e[maxn];
bool vs[maxn],fd[maxn];
int d[maxn];

void dfs(int u,int ft){
    fd[u]=1;
    for(int v:e[u])if(v!=ft&&vs[v])dfs(v,u);
}

void dfs1(int u,int ft){
    d[u]=min(d[u],d[ft]+1);
    for(int v:e[u])if(v!=ft)dfs1(v,u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans=n+1;
        for(int s=0;s<(1<<n);s++){
                int sk=0;
            for(int i=0;i<n;i++){
                vs[i+1]=(s>>i&1);
                if(vs[i+1])d[i+1]=0,sk++;
                else d[i+1]=n+1;
            }
            if(sk!=k)continue;
            for(int i=1;i<=n;i++)fd[i]=0;
            int c=0;
            for(int i=1;i<=n;i++){
                if(fd[i]||!vs[i])continue;
                dfs(i,0);
                c++;
            }
            for(int i=1;i<=n;i++)if(vs[i])dfs1(i,0);
            if(c<=2){
                int sn=0;
                for(int i=1;i<=n;i++)sn=max(sn,d[i]);
                ans=min(ans,sn);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
