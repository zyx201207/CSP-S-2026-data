#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
ll a[N];
ll n,m,maxn;
bool cmp(ll x,ll y){
	return x<y;
}
ll cha[N];
ll pre[N];
bool check(int len){
	for(int i=1;i<=n-len+1;i++){
		ll j = i+len-1;
		ll ans = 1ll * (a[j] * (len - 1) - (pre[j-1] - pre[i-1]));
		if(ans <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	pre[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn = max(maxn,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1] + a[i];
	}
	ll l = 1,r = max(m,maxn);
	ll ans;
	while(l<r){
		int mid = (l+r)/2;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	if(check(ans+1) == true) cout<<ans+1;
	else cout<<ans;
	return 0;
} 
