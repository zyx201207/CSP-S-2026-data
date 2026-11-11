#include <bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int c, t, n, k;
vector<int> g[1005];
bool col[1005];
int dfs(int x, int fa){//O(n)
    if(col[x])return 0;
    int tmp=0x3f3f3f3f;
    for(int y:g[x]){
        if(y==fa)continue;
        tmp=min(tmp,dfs(y,x)+1);
    }
    return tmp;
}
int fa[15];int rt(int x){return(x==fa[x]?x:fa[x]=rt(fa[x]));}
bool judge(){
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=n;++i){
        if(col[i]){
            for(int j:g[i]){
                if(col[j])fa[rt(i)]=rt(j);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i)if(col[i]&&fa[i]==i)++cnt;
    return (cnt<=2);
}
int check(){//O(n^2)
    if(!judge())return 0x3f3f3f3f;
    int res=0;for(int i=1;i<=n;++i)res=max(res, dfs(i,0));return res;
}
int ans;
void force(int r,int c){//O(2^n * n^2)
    if(r>n){if(c==k)ans=min(ans,check());return;}
    if(c>k)return;
    col[r]=1;force(r+1,c+1);
    col[r]=0;force(r+1,c);
}
void solve(){
    ans=0x3f3f3f3f;
    cin>>n>>k;for(int i=1;i<=n;++i)g[i].clear();
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;g[u].push_back(v),g[v].push_back(u);
    }
    force(1,0);
    cout<<ans<<'\n';
}
int main() {
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    faster;
    cin>>c>>t;while(t--)solve();
    return 0;
}
//zap
