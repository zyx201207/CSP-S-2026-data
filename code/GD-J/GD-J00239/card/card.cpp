#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m;
int a[N];
int f[N];
int to[N];
int tto[N];
int lst[N];
int cnt[N];
vector<int>g[N];
int siz[N];
void dfs(int u){
    siz[u]=1;
    for(int v:g[u]){
        dfs(v);
        siz[u]+=siz[v];
    }
    if(u<=n){
        cnt[a[u]]+=siz[u];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        lst[i]=n+1;
    }
    for(int i=n;i>=1;i--){
        to[i]=lst[a[i]];
        if(to[i]>n)tto[i]=i;
        else tto[i]=tto[to[i]];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        g[tto[i]+1].push_back(i);
    }
    dfs(n+1);
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}