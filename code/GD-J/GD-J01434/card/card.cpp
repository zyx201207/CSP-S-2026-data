#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[500005], ans[300005];
bool ok[300005];
bool flag = true;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	a[0] = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i - 1] > a[i]) flag = false;
	}
	if(flag){
		for(int i = 1; i <= n; ++i){
			if(a[i - 1] < a[i]) {
				ans[a[i - 1]] = i - 1;
			}
		}
		for(int i = 1; i <= m; ++i) cout << ans[i] << ' ';
		return 0;
	}
	if(n <= 500){
		vector<ll> vec;
		for(int i = 1; i <= n; ++i){
			memset(ok, false, sizeof ok);
			vec.clear();
			vec.push_back(a[i]);
			ok[a[i]] = true;
			for(int j = i + 1; j <= n; ++j){
				if(ok[a[j]]){
					for(int k = 0; k <= int(vec.size()) - 1; ++k)
						if(vec[k] == a[j]) vec.erase(vec.begin() + k, vec.end());
					vec.push_back(a[j]);
				}
				else{
					vec.push_back(a[j]);
					ok[a[j]] = true;
				}
			}
			for(auto tar : vec) ans[tar]++;
		}
		for(int i = 1; i <= m; ++i) cout << ans[i] << ' ';
		return 0;
	}
	return 0; 
}
