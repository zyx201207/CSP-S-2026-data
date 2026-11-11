#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
vector<pair<int, int> > v[33];
int n, m, ans, cnt[33];
bool vis[N];
void dfs(int u){
	ans += 1 << u,
	memset(cnt, 0, sizeof(cnt));
	for (auto i : v[u])
		if (vis[i.second]){
			for (int j = u; j + 1; j --)
				if (i.first & (1 << j))cnt[j] ++;
		}
	for (int i = u - 1; i + 1; i --)
		if (cnt[i] >= m){
			for (auto j : v[u])
				if (!(j.first & (1 << i)))
					vis[j.second] = 0;
			dfs(i);break;
		}
}int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		int x;cin >> x;
		for (int j = 30; j + 1; j --)
			if (x & (1 << j))
				v[j].push_back({x, i});
	}for (int i = 30; i + 1; i --)
		if (v[i].size() >= m){
			for (auto j : v[i])vis[j.second] = 1;
			dfs(i);break;
		}
	return cout << ans, 0;
}
//freopen("and.in", "r", stdin);
//freopen("and.out", "w", stdout);
