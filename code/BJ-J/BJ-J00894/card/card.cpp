#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],st1;
deque <int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      q.push_back(a[i]);
   }
   for(int i=1;i<=n;i++){
       int st=0;
       int z[500005]={};
       for(int j=i;j<=n;j++){
          for(int k=1;k<=st;k++){
              if(z[k]==q[j]){
                 for(int q1=k;q1<=st;q1++){
                    q.push_back(z[q1]);
                    z[q1]=0;
                 }
                 st=k-1;
                 break;
              }
          }
          z[++st]=q[j];
          q.erase(q.begin()+j);
       }
       for(int cnt=1;cnt<=st;cnt++){
           ans[z[cnt]]++;
       }
   }
   for(int i=1;i<=m;i++){
      cout<<ans[i]<<" ";
   }
   return 0;
}
