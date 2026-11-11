#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,ans = -1;
ll a[500010];
unsigned ll pre[500010];

ll read(){
	ll res = 0;
	int f = 1;
	char c = getchar();
	while(!isdigit(c)){
		if(c == '-')f = -1;
		c = getchar();
	}
	while(isdigit(c)){
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}

void init(){
	n = read();
	m = read();
	for(ll i = 1;i <= n;i++){
		a[i] = read();
	}
	sort(a + 1,a + n + 1);
	pre[1] = 0;
	for(ll i = 2;i <= n;i++){
		pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
}

ll rge(ll l,ll r){
	return (pre[r] - pre[l]) - (l - 1) * (a[r] - a[l]);
}

ll solve(ll idx){
	ll l = 1,r = idx,mid,res;
	while(l <= r){
		mid = (l + r) / 2;
		if(rge(mid,idx) <= m){
			res = idx - mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return res + 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init();
	for(ll i = 1;i <= n;i++){
		ll t = solve(i);
		ans = max(ans,t);
	}
	cout << ans;
	
	return 0;
}
