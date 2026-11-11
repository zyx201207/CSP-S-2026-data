#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6+5;
ll c, t, n, d;
ll x[N], diff[N];

ll land_cnt(ll l, ll r){
	ll right = upper_bound(x+1, x+1+n, r)-x, left = lower_bound(x+1, x+1+n, l)-x;
	return right-left;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;++i) cin >> x[i];
		diff[1] = 1;
		for(int i=2;i<=n;++i){
			if(x[i]-x[i-1]>d){
				diff[i] = x[i];
			}else{
				diff[i] = diff[i-1];
			}
		}
		ll l=1, r=4, cnt=0;
		while(r<=n){
			while(x[r]-x[l]>=2*d || land_cnt(x[r]-d, x[l]+d)>2){
				l++;
				if(l>n) break;
			}
			while(x[r]-x[l]<=d || land_cnt(x[r]-d, x[l]+d)<2){
				r++;
				if(r>n) break;
			}
			if(r>n) continue;
			//cout << l << r;
			cnt++; //最简
			ll ex = (l-diff[l])/d;
			cnt += ex; //扩展
			if(ex && land_cnt(l-ex*d, diff[l]+d)==1) cnt++; //特判尾部 
			r++;
		}
		cout << cnt << endl;
	}

	return 0;
}
