#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5+5;
ll n,m;
vector<int> a(N),pre(N);

bool check(ll mid){
	for(int i = 1;i<=n-mid;++i){
		ll j = i+mid-1;
		ll op = pre[j]-pre[i]-(i-1)*abs(a[j]-a[i]);
		if(op <= m) return true;
		else return false;
	}
}


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i<=n;++i) cin >> a[i];

	sort(a.begin(),a.end());
	
	pre[1] = 0;
	for(int i = 2;i<=n;++i){
		pre[i] = pre[i-1]+abs(a[i]-a[i-1])*(i-1);
	}
	
	
	ll l = 1,r = n,ans = 0;
	while(l<=r){
		ll mid = l+(r-l)/2;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	
	
	
	cout << ans;
}
