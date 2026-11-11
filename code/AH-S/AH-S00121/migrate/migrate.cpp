#include<bits/stdc++.h>
using namespace std;
void solve(){
   int n;
   long long d;
   cin>>n>>d;
   vector<long long> a(n);
   for(long long i=1;i<=n;i++) cin>>a[i];
   int ans=0;
   for(long long i=1;i<=n;i++){
      if(a[i]==1&&a[i]==3&&a[i]==4&&d>=2) ans++;
      if(a[i]==2&&a[i]==4&&a[i]==5&&d>=2) ans++;
      if(a[i]==3&&a[i]==5&&a[i]==6&&d>=2) ans++;
      if(a[i]==4&&a[i]==6&&a[i]==7&&d>=2) ans++;
      if(a[i]==5&&a[i]==7&&a[i]==8&&d>=2) ans++;
      if(a[i]==6&&a[i]==8&&a[i]==9&&d>=2) ans++;
      if(a[i+1]-a[i]==1) ans+=a[n]-3;
   }
   cout<<ans<<'\n';
}

int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   int c,t;
   cin>>c>>t;
   while(t--){
      solve();
   }

   return 0;
}
