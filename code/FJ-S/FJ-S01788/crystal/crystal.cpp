#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2e17;

inline ll qread(){
	ll x = 0, f = 1;
	char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c=getchar()) x = x*10+c-48;
	return x * f;
}

ll n, m;
vector<ll> a, pre;

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = qread(); m = qread();
	a.resize(n);
	for(int i = 0; i<n; i++) a[i] = qread();
	sort(a.begin(), a.end());
	pre.resize(n+1, 0);
	for(int i = 1; i<=n; i++) pre[i] = pre[i - 1] + a[i - 1];
	
	ll l = 0, r = n-1, ans = 0;
	while(l <= r){
		ll mid = l + (r - l) / 2;
		if(pre[mid] + m >= mid * a[mid - 1]){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	
	printf("%lld", ans);
	return 0;
}