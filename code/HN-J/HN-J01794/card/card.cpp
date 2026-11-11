#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, M = 2e5 + 5;

int n, m, a[N], res[N], vis[N];
vector<int> v;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			vis[j] = 0;
		}
		v.clear();
		for(int j = i; j <= n; ++j){
			if(!vis[a[j]]){
				v.push_back(a[j]);
				vis[a[j]] = 1; 	
			}else{
				for(; v.back() != a[j]; vis[v.back()] = 0, v.pop_back());
			}
		}
		for(auto x : v){
			res[x]++;
		}
	}
	for(int i = 1; i <= m; ++i){
		cout << res[i] << ' ';
	}
	return 0;
}

