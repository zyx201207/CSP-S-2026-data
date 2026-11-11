#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500010];
long long b[500010],sum[500010];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
scanf("%d%lld",&n,&m);
for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
for(int i=1;i<n;i++)b[i]=a[n]-a[i];
for(int i=n-1;i>=1;i--)sum[i]=sum[i+1]+b[i];
for(int i=n-1;i>=1;i--){
	if(sum[i]<=m)ans++;
	else break;
}
printf("%d",ans);
return 0;
}
