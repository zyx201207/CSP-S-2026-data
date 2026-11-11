#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int n,m,ans = 0;
int a[500002],f[500002];
int cpt(int r,int y){//最右面的选的r，连续选了y个 
	return a[r] * y - (f[r] - f[r - y]); 
}

bool check(int mid){
	for (int i = mid;i <= n;i++){
		if (cpt(i,mid) <= m){
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++){
		f[i] = f[i - 1] + a[i];
	} 
	
	int l = 1,r = n;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)){
			ans = max(ans,mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%lld",ans);
}
