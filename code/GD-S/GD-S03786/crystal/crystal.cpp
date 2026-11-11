#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n , m;
ll a[N];
ll ans = LLONG_MIN;
ll cal(ll k){
	ll res = m , p = 0;
	priority_queue<ll , vector<ll> , greater<ll> > pq1;
	for(int i = 1;i <= n;++i){
		if(k - a[i] >= 0)pq1.push(k - a[i]);
	} 
	while(!pq1.empty()){
		if(pq1.top() <= res){
			res -= pq1.top();
			++p;
		}else{
			break;
		}
		pq1.pop();
	}
	return p;
}
bool check(ll k , ll p){
	priority_queue<ll , vector<ll> , greater<ll> > pq1;
	for(int i = 1;i <= n;++i){
		if(k - a[i] >= 0) pq1.push(k - a[i]);
	} 
	ll b = cal(k);
	if(b < p) return false;
	while(!pq1.empty()){
		if(pq1.top() <= m){
			return true;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout); 
	cin >> n >> m;
	ll l = 1e12 , r = -1e12;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		l = min(l , a[i]);
		r = max(r , a[i]);
	}
	l--;
	r++;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid , ans)){
			ans = max(ans , cal(mid));
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 
