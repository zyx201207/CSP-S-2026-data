#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long n,m;
bool check(long long mid){
	long long sum = -m;
	for(long long i = 1;i < mid;i++) sum += a[mid] - a[i];
	if(sum > 0) return 0;
	else return 1;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	stable_sort(a + 1,a + 1 + n);
	bool flag = 0,f = a[2] - a[1];
	for(int i = 3;i <= n;i++){
		if(a[i] - a[i - 1] == f) flag = 1;
	}
	if(flag){
		printf("%lld",m / f);
	}
	long long l = 1,r = n,ans;
	while(l <= r){
		long long mid = l + ((r - l) >> 1);
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	printf("%lld",ans);
	return 0;
}

