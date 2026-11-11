#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int Nn=15;
const int N=1e6+5;
int c,t;
int n,k;
vector<int> g[N];
int fa[N],dep[N],siz[N],son[N];
void dfs1(int u,int f){
  fa[u]=f;
  dep[u]=dep[f]+1;
  siz[u]=1;
  son[u]=0;
  for(int v:g[u]){
    if(v==f) continue;
    dfs1(v,u);
    siz[u]+=siz[v];
    if(!son[u]||siz[son[u]]<siz[v]) son[u]=v;
  }
}

int top[N];
void dfs2(int u,int f){
  top[u]=f;
  if(son[u]){
    dfs2(son[u],f);
    for(int v:g[u]){
      if(v==fa[u]||v==son[u]) continue;
      dfs2(v,v);
    }
  }
}
int lca(int u,int v){
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]]) swap(u,v);
    u=fa[top[u]];
  }
  if(dep[u]>dep[v]) swap(u,v);
  return u;
}
int dis(int u,int v){
  return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  cin>>c>>t;
  while(t--){
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,1);
    if(k==2){
      int ans=1e9;
      for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
          if(i==j) continue;
          for(int x=1;x<=n;x++){
            ans=min(ans,max(dis(i,x),dis(j,x)));
          }
        }
      }
      cout<<ans<<'\n';
      continue;
    }
    if(n>25){
      cout<<"0\n";
      continue;
    }
    int ans=1e9;
    for(int mask=0;mask<(1<<n);mask++){
      if(__builtin_popcount(mask)!=k) continue;
      int tmp=0;
      for(int i=0;i<n;i++){
        if((mask>>i)&1) continue;
        for(int j=0;j<n;j++){
          if((mask>>j)&1){
            tmp=max(tmp,dis(i+1,j+1));
          }
        }
      }
      ans=min(ans,tmp);
    }
    cout<<ans<<'\n';
  }
  cout.flush();
  return 0;
}