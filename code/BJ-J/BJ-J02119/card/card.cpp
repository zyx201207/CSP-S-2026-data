#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000001],b[1000001],nxt[1000001],in[1000001],sz[1000001],ans[1000001];
void bfs(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        sz[i]=1;
        if(!in[i])q.push(i);
    }
    while(q.size()){
        int u=q.front(),v=nxt[u];
        q.pop(),sz[v]+=sz[u];
        if(!--in[v])q.push(v);
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]=i;
    for(int i=1;i<=n;i++)nxt[i]=b[a[i]]+1,in[nxt[i]]++;
    bfs();
    for(int i=1;i<=n;i++)ans[a[i]]+=sz[i];
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
