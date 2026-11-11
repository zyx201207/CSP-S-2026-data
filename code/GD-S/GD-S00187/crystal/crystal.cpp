#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int n,m;
const ll MAXN = 500006;
ll a[MAXN];
ll cf[MAXN];//cf[i] = a[i + 1] - a[i]
ll check(ll x){
	if (x == 1) return 0;
	int t = m;
	bool ok = 1;
	ll tans = 0;
	int nw = x;
	ll de = 0;
	while(ok && nw >= 1 && nw <= n){
		de += cf[nw - 1];
		//cout << "de:" <<de;
		if (t - de >= 0){
			tans++;
			t -= de;
			nw--;
		}else ok = 0;
	}
	//cout << "checkscs" << x << " "<< tans+1 << endl;
	return tans + 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	cf[1] = 0;
	for(int i = 1; i < n; i++){
		cf[i] = abs(a[i + 1] - a[i]);
	}
	cf[n + 1] = 999;
	//cout << cf[10] << endl;
	int l = 2,r = n + 1;
	ll ans = -1;
	while(l <= r && l <= n + 1 && r <= n + 1){
		int mid = (l + r) / 2;
		int umid = mid;
		int dmid = mid;
		while(a[umid] == mid){
			umid++;
		}
		while(a[dmid] == mid){
			dmid--;
		}
		//cout << "ck" << endl;
		ll res = check(umid);
		if(res > ans) ans = res;
		ll tmpm = umid + 1;
		while(1){
			//cout << "wl:" << endl;
			int ttt = check(tmpm);
			if (ttt < ans){
				r = dmid - 1;
				break;
			}else if(ttt > ans){
				l = tmpm;
				//cout << "l:" << l << "r:" << r << endl;
				break;
			}
			tmpm++;
		}
		//cout <<"end" << endl;
	}
	cout << ans<<endl;
	//cout << l;
}
