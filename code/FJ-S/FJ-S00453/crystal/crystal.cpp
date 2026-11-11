#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const ll MAXN = 1e18 + 5;
int n, ans = 1;
ll a[N], m, b[N], s[N], ss[N];
ll add(int l, int r){
	if(r - l == 1)return b[l];
	return ss[l] - ss[r] - s[r] * (r - l);
}
bool check(int l, int r){
	ll sum = add(l, r);
	if(sum > m)return 0;
	return 1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i < n; i++){
		b[i] = a[i + 1] - a[i];
	}
	for(int i = n; i >= 1; i--){
		s[i] = s[i + 1] + b[i];
		ss[i] = ss[i + 1] + s[i];
	}
	for(int i = 2; i <= n; i++){
		int l = 1, r = i - ans;
		while(l < r){
			int mid = (l + r)/2;
			if(check(mid, i)){
				r = mid;
			}else{
				l = mid + 1;
			}
		}
		ll sum = add(l, i);
		if(sum > m)continue;
		ans = max(ans, i - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}

