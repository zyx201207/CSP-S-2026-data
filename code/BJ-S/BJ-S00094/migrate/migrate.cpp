#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   int r,t,n,m,a[1006],da[1005],ji=0;
   cin>>r>>t;
   for(int i=1;i<=t;i++){
      cin>>n>>m;
      for(int i=1;i<=n;i++){
        cin>>a[i];
      }
      int aa=a[n]-a[1];
      if(aa<m){
          ji++;
        da[ji]=0;
      }
      else if(aa>=m){
          ji++;
       da[ji]=aa/m;
      }
   }
for(int i=1;i<=ji;i++){
    cout<<da[i]<<endl;
}
   return 0;
}