#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],nxt[N],ls[M],ans[M];
vector<int> g[N];
int dfs(int u,int fa){
    int sz=1;
    for(int v:g[u]) sz+=dfs(v,u);
    if(a[u]!=a[fa]) ans[a[u]]+=sz;
    return sz;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(ls[a[i]])
            nxt[ls[a[i]]]=i;
        nxt[i]=i+1;
        ls[a[i]]=i;
    }
    for(int i=1;i<n;i++)
        g[nxt[i]].push_back(i);
    dfs(n,0);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}