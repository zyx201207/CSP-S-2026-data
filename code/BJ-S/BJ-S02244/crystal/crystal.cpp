#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005],c[500005],f[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
   cin>>a[i];
   if(i==1) continue;
   c[i]=a[i]-a[i-1];
   if(i==2) f[i]=c[i];
   if(i>2) f[i]=c[i]*(i-1)+f[i-1];
   if(f[i]<=m) ans=i;
}
cout<<ans;
return 0;
}
