#include<bits/stdc++.h>
using namespace std;
const int K=5e5+10;
const int N=100;
bool vis[N];
int ans;
int c,n,m,d,q,w[K],k[N],a[N][K],t[N][K],t1[N][K];
vector<int>p[N];
void dfs(int x,int y,int sum){
if(x==y){ans=min(ans,sum+w[y]);return;}
vis[x]=1;
for(int top:p[x]){
    for(int i=1;i<=k[top];i++){
    if(!vis[a[top][i]]){
    dfs(a[top][i],y,sum+t[top][a[top][i]]+t[top][x]);
    vis[a[top][i]]=0;
      }
    }
}
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++)cin>>w[i];
for(int i=1;i<=n;i++){
   cin>>k[i];
   for(int j=1;j<=k[i];j++){cin>>a[i][j]>>t[i][a[i][j]];p[a[i][j]].push_back(i);}
}
while(q--){
int x,y;
ans=1e9;
cin>>x>>y;
memset(vis,0,sizeof(vis));
dfs(x,y,w[x]);
cout<<ans<<endl;
}
return 0;
}
