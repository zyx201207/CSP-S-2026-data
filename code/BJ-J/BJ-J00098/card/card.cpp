#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[300001],a[500001];
int vis[300001];
stack<long long >s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   cin>>n>>m;
   int t=1;
   for(int i=1;i<=n;i++){
       cin>>a[i];
        if(a[i]<a[i-1])t=0;
   }
   if(t){
       for(int i=1;i<=n;i++){
           if(a[i]!=a[i-1]&&i!=1)cout<<i-1<<' ';
       }
       cout<<n<<endl;
   }
  for(int i=1;i<=n;i++){
      memset(vis,0,sizeof(vis));
       for(int x=i;x<=n;x++){
        if(!vis[a[x]]){
            vis[a[x]]=1;
            s.push(a[x]);
        }else{
            while(!s.empty()&&s.top()!=a[x]){
                vis[s.top()]=0;
                s.pop();
            }
             
        }
       }
      while(!s.empty()){
          //cout<<s.top();
          ans[s.top()]++;
          s.pop();
      }
      //cout<<endl;
   }
   for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}