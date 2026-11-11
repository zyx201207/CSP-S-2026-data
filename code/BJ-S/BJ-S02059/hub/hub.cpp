#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+6;
int fa[N],dep[N],DEP[N],an;
bool ok[N];
vector<int>e[N],sol,res;
void dfs(int u,int f){
    fa[u]=f;
    DEP[u]=DEP[f]+1;
    for(int v:e[u]){
        if(v==f)continue;
        dfs(v,u);
    }
}
void dfs2(int u,int d){
    dep[u]=0;
    int mn=0,fr=-1;
    for(int v:e[u]){
        if(v==fa[u])continue;
        dfs2(v,d);
        dep[v]++;
        if(dep[v]<mn){
            mn=dep[v],fr=v;
        }
    }
    dep[u]=mn;
    for(int v:e[u]){
        if(v==fa[u])continue;
        if(v==fr)continue;
        if(dep[v]+mn>=0)dep[u]=max(dep[u],dep[v]);
        else dep[u]=max(dep[u],dep[v]+mn);
    }
   // cout<<u<<":"<<dep[u]<<' ';
    if(dep[u]==d){
        dep[u]=-d-1;
        an++;
        ok[u]=1;
    }else if(u==1&&dep[u]>0){
        dep[u]=-d-1;
        an++;
        ok[u]=1;
    }
}
void dfs3(int u,int tp){
    if(ok[u]){
        if(tp)sol.push_back(DEP[u]-DEP[tp]-1);
        else if(u!=1)res.push_back(DEP[u]-DEP[1]-1);
        for(int v:e[u]){
            if(v==fa[u])continue;
            dfs3(v,u);
        }
    }else{
        for(int v:e[u]){
            if(v==fa[u])continue;
            dfs3(v,tp);
        }
    }
}
int n,k;
bool ck(int d){
    an=0;
    //cout<<d<<":";
    dfs2(1,d);
    dfs3(1,0);
   // cout<<'\n';
    sort(sol.begin(),sol.end());
    for(int i=0;i+1<sol.size();i++){
        an+=sol[i];
    }
    if(res.size()>1){
        an++;
        sort(res.begin(),res.end());
        for(int i=0;i+1<res.size();i++){
            an+=res[i];
        }
        if(!sol.empty())an+=min(sol.back(),res.back());
        else an+=res.back();
    }
    sol.clear();
    res.clear();
    for(int i=1;i<=n;i++){
     //   if(ok[i])cout<<i<<" ";
        ok[i]=0;
    }
  //  cout<<an<<' ';
  //  cout<<'\n';
    return an<=k;
}
int l,r,mid,ans;
int C,T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(n==k){
            cout<<"0\n";
            for(int i=1;i<=n;i++){
                e[i].clear();
            }
            continue;
        }
        dfs(1,0);
        l=1,r=ans=n-1;
        while(l<=r){
            mid=l+r>>1;
            if(ck(mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


0 1
14 4
1 2
1 3
1 4
2 5
3 9
4 6
9 8
8 7
10 3
12 4
13 3
14 1
11 12

0 1
20 5
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 11
1 12
1 13
2 14
2 15
3 16
3 17
11 18
11 19
19 20
*/
