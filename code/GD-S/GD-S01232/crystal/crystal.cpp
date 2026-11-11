#include<iostream>
#include<algorithm>
using namespace std;
long long a[500010], sum[500010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, ans=0;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=0, r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-(sum[i]-sum[mid])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans, i-l);
	}
	printf("%d", ans);
	return 0;
}
