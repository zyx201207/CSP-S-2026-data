#include <bits/stdc++.h>
using namespace std;
long long a[1000000+10];
int main(){

   freopen("crystal,in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
for(long long i=1;i<=n;i++){
        cin>>a[i];
}
sort(a,a+n);
int ans=0;
for(long long i=1;i<=n;i++){
  if(a[i]<a[i+1] and ans<=m){
         max(a[i],max(a[i+1],a[+2]));
         ans++;
        }
cout<<ans;
return 0;
}

