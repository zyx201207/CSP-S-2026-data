#define fastio ios::sync_with_stdio(0);cin.tie(0);
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=1e6+35;

int n,k;
vector<int> e[maxn];
void input(){
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
}


int fa[maxn];
vector<int> sons[maxn];
void dfs(int x,int father){
    fa[x]=father;
    for(auto y: e[x]){
        if(y==father) continue;
        dfs(y,x);
        sons[x].push_back(y);
    }
}

namespace SOLVE1{
    bool choose[maxn];
    bool vis[maxn];
    void dfs2(int x){
        vis[x]=1;
        for(auto y: e[x]){
            if(vis[y]) continue;
            if(!choose[y]) continue;
            dfs2(y);
        }
    }
    int dfs3(int x,int father,int dis){
        if(choose[x]){
            return dis;
        }
        int mindis=1e9;
        for(auto y: e[x]){
            if(y==father) continue;
            int ret=dfs3(y,x,dis+1);
            mindis=min(mindis,ret);
        }
        return mindis;
    }
    void solve(){
        ll ans=inf;
        for(int S=0;S<(1<<n);++S){
            int choosecnt=0;
            for(int i=1;i<=n;++i){
                if(S&(1<<(i-1))) choose[i]=1,++choosecnt;
                else choose[i]=0;
            }
            if(choosecnt!=k) continue;

            int cnt=0;
            for(int i=1;i<=n;++i){
                if(choose[i]&&!vis[i]) dfs2(i),++cnt;
            }
            if(cnt<=2){
                ll mxdis=0;
                for(int i=1;i<=n;++i){
                    ll dis=dfs3(i,0,0);
                    mxdis=max(mxdis,dis);
                }
                ans=min(ans,mxdis);
            }
            memset(vis,0,sizeof(vis[0])*(n+5));
        }
        printf("%lld\n",ans);
    }
}

void reset(){
    memset(fa,0,sizeof(fa[0])*(n+5));
    for(int i=0;i<=n+5;++i){
        sons[i].clear();
        e[i].clear();
    }
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    fastio;
    int ccc,T;
    cin>>ccc>>T;
    while(T--){
        input();
        dfs(1,0);
        if(n<=10) SOLVE1::solve();
        reset();
    }
    return 0;
}
