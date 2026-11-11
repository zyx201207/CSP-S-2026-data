#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
vector<vector<int>> g;
bool vis[N];
int a[N];
vector<int> get(int t){
	vector<int> ans;
	while(t > 0){
		ans.push_back(t % 2);
		t /= 2;
	}
	return ans;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	g.push_back({}); 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		g.push_back(get(a[i]));
	}
	int mxsiz = 0;
	for(int i = 1; i <= n; i++){
		mxsiz = max(mxsiz, (int)g[i].size());
	}
	for(int i = 1; i <= n; i++){
		while(g[i].size() < mxsiz){
			g[i].push_back(0);
		}
		reverse(g[i].begin(), g[i].end());
	}
//	for(int i = 1; i <= n; i++){
//		for(auto v : g[i]){
//			cout << v << ' ';
//		}
//		cout << '\n';
//	}
	for(int j = 0; j < mxsiz; j++){
		int sum = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i] == true){
				continue;
			}
			if(g[i][j] == 1){
				sum++;
			}
		}
		if(sum < m){
			continue;
		}
		for(int i = 1; i <= n; i++){
			if(g[i][j] != 1){
				vis[i] = true;
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		cout << vis[i] << '\n';
//	}
	int ans = 0;
	int flag = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i] == true){
			continue;
		}
		if(flag == 0){
			ans = a[i];
			flag++;
		}else{
			ans &= a[i];
			flag++;
		}
		if(flag == m){
			break;
		}
	}
	cout << ans;
}
/*
1 1
1


*/
