#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=0;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		long long sum=0,cnt=1;
		for(long long j=i-1;j>=1;j--){
			if(sum+a[i]-a[j]<=m){
				sum+=a[i]-a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	printf("%lld",maxn);
	return 0;
}
