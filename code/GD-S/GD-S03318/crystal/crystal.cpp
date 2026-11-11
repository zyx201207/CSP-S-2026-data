#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
long long n,m;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i = 1;i <= n;++i) scanf("%lld",&a[i]);
	sort(1 + a,1 + a + n);
	if(n <= 2000){
		int maxx = 0;
		for(int i = 1;i <= n;i++){
			int ans = 1,x = 0;
			for(int j = i - 1;j >= 1;j--){
				if(x + a[i] - a[j] > m) break;
				else x += a[i] - a[j],ans++;
			}
			maxx = max(maxx,ans);
		}
		printf("%lld",maxx);
		return 0;
	}
	for(long long i = 2;i <= n;++i) b[i] += (a[i] - a[i - 1]) * (i - 1) + b[i - 1];
	long long l = 1,r = n,mid;
	while(l <= r){
		mid = (l + r) / 2;
		if(b[mid] <= m) l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld",l - 1);
	
	return 0;
}
