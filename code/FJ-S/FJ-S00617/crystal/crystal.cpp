#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int n, m;
int a[N];
int s[N];
int ans = 1;
bool check(int l, int r){
	int k = (r-l+1) * a[r];
	int w = s[r]-s[l-1];
	return (k-w) <= m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	for (int i = 2; i <= n; i++){
		int l = 1, r = i;
		int res = n;
		while (l <= r){
			int mid = (l+r) >> 1;
			if (check(mid, i)){
				res = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}
		ans = max(ans, i-res+1);
	}
	printf("%lld", ans);
	return 0;
}
