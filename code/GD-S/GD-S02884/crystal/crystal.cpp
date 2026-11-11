#include<stdio.h>
#include<algorithm>

using ll = long long;
constexpr int N = 5e5 + 10;
ll n, m, a[N], l, r, mid, ans;
inline ll min(ll x, ll y){return x < y ? x : y;}

ll p; int f; char c;
inline ll read(){
	f = 1; p = 0; c = getchar();
	while(c > '9' || c < '0'){if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') p = (p << 1) + (p << 3) + (c ^ 48), c = getchar();
	return p * f;
}

bool chk(){
	ll sum = 0, mn;
	for(int i = 1; i < mid; i++) sum += a[mid] - a[i];
	mn = sum;
	for(int i = mid + 1; i <= n; i++) sum -= a[i - 1] - a[i - mid], sum += (mid - 1) * (a[i] - a[i - 1]), mn = min(mn, sum);
	return mn <= m;
}

int main(){
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + n + 1);
	l = 1; r = n;
	while(l <= r){
		mid = (l + r) >> 1;
		if(chk()) l = mid + 1, ans = mid; else r = mid - 1;
	}
	printf("%lld", ans);
}
