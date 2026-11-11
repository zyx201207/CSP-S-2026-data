#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum[500005],r=1,z,ans;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(long long i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+1+n);
for(long long i=1;i<n;i++){
b[i]=a[i+1]-a[i];
sum[i]=b[i]+sum[i-1];
}
for(long long l=1;l<=n;l++){
while(z+b[r]*(r-l+1)<=m && r<n){
z+=b[r]*(r-l+1);
r++;
}
ans=max(ans,r-l+1);
z-=sum[r-1]-sum[l-1];
}
cout<<ans;
return 0;
} 
