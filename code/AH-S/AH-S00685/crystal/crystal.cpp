#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long num[500005];
long long val[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m); 
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	num[1]=1;
	val[1]=0;
	long long ans=1;
	long long st=1;
	for(long long i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			val[i]=val[i-1]+(a[i]-a[i-1])*num[i-1];
			num[i]=num[i-1]+1;
			while(val[i]>m){
				val[i]=val[i]-(a[i]-a[st]);
				st++;
				num[i]--;
			}
		}else{
			val[i]=val[i-1];
			num[i]=num[i-1]+1;
		}
		ans=max(ans,num[i]);
	}
	printf("%lld\n",ans);
	return 0;
} 
