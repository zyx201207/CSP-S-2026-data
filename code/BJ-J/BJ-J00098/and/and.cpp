#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],b[200001],vis[200001],ans=0;
// long long and(long long x,long long y){
//     int x[100]={};
//     while(x){
        
//     }
// }
void dfs(int s){
    if(s>m){
        long long sum=a[b[1]];
        
        for(int i=2;i<=m;i++){
           sum&=a[b[i]];
           
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            b[s]=i;
            dfs(s+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++)cin>>a[i];
   dfs(1);
  cout<<ans;
    return 0;
}