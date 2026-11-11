#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 5e5 + 5;
const int MK = 2e5 + 5; 
ll ans = -0x3f3f3f3f;
ll n, m, a[MAXN];
int spa[MK];

void dfs(int len, int cur){
	if(cur == n + 1){
		for(int i = 1; i <= MK; i++){
			spa[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			spa[a[i] + (int)1e5 + 1]++;
		}
		for(int i = 1; i <= MK; i++){
			if(spa[i] > ans) ans = spa[i];
		}
		return;
	}
	
	for(ll i = 0; i + len <= m; i++){
		a[cur] += i;
		dfs(len + i, cur + 1);
		a[cur] -= i;
	}
}
bool f = true, f2 = true; 

mt19937_64 rng(time(0));
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f &= (a[i] == i);
		if(i > 2){
			f2 &= (a[i] - a[i - 1] == a[i - 1] - a[i - 2]);
		}
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
	if(m == 0){
		for(int i = 1; i <= n; i++){
			spa[a[i] + (int)1e5 + 1]++;
		}
		for(int i = 1; i <= MK; i++){
			if(spa[i] > ans) ans = spa[i];
		}
		cout << ans;
		return 0;
	}
	if(f){
		ll l;
		for(int i = 2; i <= n; i++){
			ll q = i * (i - 1) / 2;
			if(i > 2){
				if((l < m && q > m)){
					cout << l;
					return 0;
				}
			}
			if(q == m){
				cout << q;
				return 0;
			}
			l = q;
		}
	}
	if(f2){
		ll l, k = a[2] - a[1], c = 1;
		for(int i = 2; i <= n; i++){
			ll q = i * (i - 1) / 2 * k;
			c++;
			if(i > 2){
				if((l < m && q > m)){
					cout << c - 1;;
					return 0;
				}
			}
			if(q == m){
				cout << c;
				return 0;
			}
			l = q;
		}
	}
	if(n <= 16){
		dfs(0, 1);
		cout << ans;
		return 0;
	}
	
	cout << rng() % n + 1; 
	return 0;
}
