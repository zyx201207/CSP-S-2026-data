#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,a[500001],s[500001];
bool f=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(i>=3)if(a[i]+a[i-2]!=2*a[i-1])f=false;
	}
	if(f){
		for(long long i=1;i*a[i]-s[i]<=m&&i<=n;i++)ans++;
		printf("%lld",ans);
	}
	else{
		for(long long i=1;i<=n;i++){
			long long cnt=0;
			for(long long j=i;(j-i+1)*a[j]-a[i]-(s[j]-s[i])<=m&&j<=n;j++)cnt++;
			ans=max(ans,cnt);
		}
		printf("%lld",ans);
	}
	return 0;
} 
