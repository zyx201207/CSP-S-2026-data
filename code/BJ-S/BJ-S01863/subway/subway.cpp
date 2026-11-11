#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
struct subway{
	ll a;
	ll t;
};

ll f(ll start, ll end, map<ll, vector<subway>>& mp){
	ll minv = 1e9;
	for(subway mmp : mp[start]){
		if(mmp.a == end){
			return mmp.t;
		}
		minv = min(minv, mmp.t + f(mmp.a, end, mp));
	}
	//cout << minv << endl;
	return minv;
}

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> w(m);
	for(int i = 0; i < m; i++){
		cin >> w[i];
	}
	map<ll, vector<subway>> s, mp;
	for(int i = 0; i < n; i++){
		ll k;
		cin >> k;
		for(int j = 0; j < k; j++){
			ll aa, tt;
			cin >> aa >> tt;
			s[i].push_back({aa, tt});
		}
		
		vector<subway> tmp = s[i];
		subway prev = tmp[0];
		mp[0].push_back(prev);
		for(int i = 1; i < k; i++){
			if(i == 1){
				mp[prev.a].push_back({tmp[i].a, tmp[i].t + prev.t});
			}
			else{
				mp[prev.a].push_back(tmp[i]);
			}
			prev = tmp[i];
		}
	}
	
	
	while(q--){
		ll start, end;
		cin >> start >> end;
		cout << w[start - 1] + f(start, end, mp) + w[end - 1] << endl;
		//cout << endl;
	}
}
