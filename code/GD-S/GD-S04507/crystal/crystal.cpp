#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n , m , ans;
int a[N];
bool Apts = 1 , Bpts = 1;
short cnt[10000001] = {};
int maxn = -1e18;
map <int , bool> mp;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] != i){
			Apts = 0;
		}
		if(i != 1 && i != 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
			Bpts = 0;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(m == 0){
		for(int i = 1 ; i <= n ; i++){
			cnt[a[i]]++;
			if(cnt[a[i]] >= maxn) maxn = cnt[a[i]];
		}
		cout << maxn;
		return 0;
	}
	if(Apts){
		int sub = a[n] - a[n - 1];
		for(int i = 1 ; i <= n ; i++){
			m -= i * sub;
			if(m < 0) break;
			ans++;
		}
		cout << ++ans;
		return 0;
	}
	if(Bpts){
		int sub = a[n] - a[n - 1];
		for(int i = 1 ; i <= n ; i++){
			m -= i * sub;
			if(m < 0) break;
			ans++;
		}
		cout << ++ans;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++){
		int use = 0 , now = 0;
		if(mp[a[i]] == 0){
			int base = a[i];
			mp[a[i]] = 1;
			for(int j = 1 ; j <= n ; j++){
				if(use >= m){
					if(a[j] == base){
						now++;
					}
				}
				else if(a[j] <= base){
					use += base - a[j];
					if(use >= m){
						continue;
					}
					now++;
				}
			}
		}
		ans = max(ans , now);
	}
	cout << ans;
	return 0;
} 
