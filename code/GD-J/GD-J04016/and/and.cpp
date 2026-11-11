#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	ll len = 0, cnt = 0, a = 0;
}num[200010];

ll a[200010];

inline ll cnt(ll x){
	ll res = 0;
	while(x > 0){
		if(x & 1) res++;
		x = x >> 1;
	}
	
	return res;
}

inline ll len(ll x){
	if(x == 0) return 1;
	ll res = 0;
	while(x > 0){
		res++;
		x = x >> 1;
	}
	
	return res;
}

inline bool cmp(Node x, Node y){
	if(x.cnt == y.cnt){
		if(x.len == y.len) return x.a > y.a;
		return x.len > y.len;
	}
	return x.cnt > y.cnt;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll big = -9999999999999999;
	for(ll i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		big = max(big, a[i]);
	}
	if(m == 1){
		printf("%lld", big);
		return 0;
	}
	
	for(ll i=1; i<=n; i++){
		num[i].cnt = cnt(a[i]);
		num[i].len = len(a[i]);
		num[i].a = a[i];
	}
	sort(num+1, num+n+1, cmp);
	
	ll ans = num[1].a, times = 1;
	for(ll i=2; i<=n; i++){
		ll tem = ans&num[i].a;
		if(tem != 0){
			ans = tem;
			times++;
		}
		if(times >= m) break;
	}
	
	if(times == m) printf("%lld", ans);
	else printf("0");
	
	return 0;
}
