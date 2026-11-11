#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n, m, a[N], sum[N];
bool chk(int x){
	for(int i = x; i <= n; i++)
		if(x * a[i] - (sum[i] - sum[i - x]) <= m) return true;
	return false;
} 
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(chk(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
