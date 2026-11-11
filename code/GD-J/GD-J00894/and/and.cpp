#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,cnt[200005][35],z,p[35],f;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
p[0]=1;
for(long long i=1;i<=30;i++){
p[i]=p[i-1]*2;
}
for(long long i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+1+n);
for(long long i=1;i<=n;i++){
z=0;
while(a[i]>0){
cnt[i][z]=cnt[i-1][z]+a[i]%2;
a[i]/=2;
z++;
}
for(long long j=z;j<=30;j++){
cnt[i][j]=cnt[i-1][j];
}
}
for(long long i=1;i<=n-m+1;i++){
f=0;
for(long long j=0;j<=30;j++){
if(cnt[i+m-1][j]-cnt[i-1][j]==m){
f+=p[j];
}
}
ans=max(ans,f);
}
cout<<ans;
return 0;
} 
