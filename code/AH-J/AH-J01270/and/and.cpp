#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int prefix[N];
int n, m;
vector<int> a(N);

vector<int> path;
int ans = -1e9;
void dfs(int pos){
	if (pos > n){
		int cnt = path.size();
		if (cnt != m) return;
		int tool = a[path[0]];
		for (auto x : path){
			tool &= a[x]; 
		}
		ans = max(ans, tool);
		return;
	}
	
	path.push_back(pos);
	dfs(pos+1);
	path.pop_back();
	
	dfs(pos+1);
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
	}

	dfs(1);
	cout << ans;
}
