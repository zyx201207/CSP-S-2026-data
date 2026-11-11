#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m;
int a[N],nxt[N],rt[N],siz[N];
vector<int>tr[N];
void dfs(int u){
    siz[u]=1;
    for(int v:tr[u]){
        dfs(v);
        siz[u]+=siz[v];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(rt[a[i]])nxt[rt[a[i]]]=i;
        rt[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(nxt[i])tr[nxt[i]].emplace_back(i);
        else tr[i+1].emplace_back(i);
    }
    dfs(n+1);
    for(int i=1;i<=m;i++)cout<<siz[rt[i]]<<' ';
    return 0;
}