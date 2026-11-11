#include<bits/stdc++.h>
using namespace std;
const int N=1000005,INF=0x3f3f3f3f;
vector<int> v[N];
int n,k,ans,cnt,d[N],use[N],vis[N];
void dfs1(int x){
    vis[x]=1;
    for(auto y:v[x])  if(use[y]&&!vis[y])  dfs1(y);
}
void check(){
    if(cnt!=k)  return void();
    int cc=0,res=0;queue<int> q;
    fill(vis,vis+n+1,0),fill(d,d+n+1,-1);
    for(int i=1;i<=n;i++){
        if(!use[i]||vis[i])  continue;
        if(++cc>2)  return void();
        dfs1(i);
    }
    for(int i=1;i<=n;i++)
        if(use[i])  d[i]=0,q.push(i);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(auto y:v[x])
            if(d[y]==-1)
                d[y]=d[x]+1,q.push(y);
    }
    for(int i=1;i<=n;i++)  res=max(res,d[i]);
    ans=min(ans,res);
}
void dfs0(int x){
    if(x>n)  return check();
    use[x]=0,dfs0(x+1);
    if(cnt<k)  cnt++,use[x]=1,dfs0(x+1),cnt--;
}
void baoli(){ans=INF,dfs0(1),cout<<ans<<"\n";}
void specialA(){
    cout<<(n==k?0:max((n/2+2-k+3)/4,1))<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)  v[i].clear();
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            v[x].push_back(y),v[y].push_back(x);
        }
        c<=3?baoli():specialA();
    }
}