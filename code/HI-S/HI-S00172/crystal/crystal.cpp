#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,sum,ans,add;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	l=1;
	ans=1;
	for(long long j=2;j<=n;j++){
		add=(a[j]-a[j-1])*(j-l);
		while(sum+add>m){
			sum=sum-(a[j]-a[l]);
			l++;
		}
		sum+=add;
		ans=max(ans,j-l+1);
	}
	printf("%lld",ans);
	return 0;
}
