#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],s[N];
long long n,m,ans;
bool cmp(long long a,long long b){
	return  a<b;
}
void su(long long b){
	memset(s,0,sizeof(s));
	for(long long i=b;i>=1;i--){
		s[i]=s[i+1]+a[i];
	}
	for(long long i=b;i>=1;i--){
		s[i]=s[i]+s[i+1];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
	}	
	for(long long i=1;i<=n;i++){
		su(n-i);
		long long cnt=1;
		for(long long j=n-i;j>=1;j--){
			if(s[j]<=m){
				cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
