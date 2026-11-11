#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5; 
#define int long long
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		sum[i] = a[i] + sum[i - 1];
	}
	int l = 1;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		while((a[i] * (i - l + 1)) - (sum[i] - sum[l - 1]) > m) l++;
		ans = max(ans,i - l + 1);
	}
	printf("%lld",ans);
	return 0;
}


