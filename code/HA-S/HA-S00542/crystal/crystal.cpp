#include<bits/stdc++.h>
using namespace std;
long long n,m;
int maxx=-500007;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		for(int cnt=1;cnt<i;cnt++){
			if(cnt*a[i]-(sum[i-1]-sum[i-cnt-1])>m){
				break;
			}
			if(cnt*a[i]-(sum[i-1]-sum[i-cnt-1])<=m){
				maxx=max(maxx,cnt+1);
			}
		}
	}
	printf("%d",maxx);
	return 0;
}
