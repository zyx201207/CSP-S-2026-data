#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],nxt[N],pos[N],c[N],siz[N],ans[N];
vector <int> g[N];
void dfs(int u){
    siz[u]=1;
    for(auto v:g[u]){
        dfs(v);
        siz[u]+=siz[v];
    }
    if(c[u]){
        //cout<<u<<" "<<c[u]<<" "<<siz[u]<<ans[c[u]]<<" "<<endl;
        ans[c[u]]+=siz[u];
    }
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;--i){
        if(pos[a[i]]) nxt[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    c[n]=a[n];
    for(int i=n-1;i>=1;--i){
        if(nxt[i]){
            g[nxt[i]].push_back(i);
        }else{
            g[i+1].push_back(i);
            c[i]=a[i];
        }
    }

    dfs(n);
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}
