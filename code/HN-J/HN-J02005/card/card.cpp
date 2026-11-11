#include <bits/stdc++.h>
#define ll long long
//#define debug(x) cout << #x << ' ' << x << endl;

using namespace std;

vector<int>va;
vector<vector<int>>ve; 
map<int, int>mp, ans;
vector<int>sz;
void dfs(int now) {
	mp[va[now]]++;
	for (auto p : ve[now]) {
		dfs(p);
		sz[now] += sz[p];
	}
	mp[va[now]]--;
	if(mp[va[now]] == 0) {
		ans[va[now]] += sz[now];
	}
//	debug(now);
//	debug(sz[now]);
}
int main() {
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0); 
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	va.resize(n + 1);
	sz.resize(n + 1, 1);
	ve.resize(n + 1);
	map<int, int>fdlst{};
	for (int i = 1;i <= n;i++) {
		cin >> va[i];
	}
	for (int i = n;i >= 1;i--) {
		if(fdlst[va[i]] == 0) {
			if(i + 1 <= n){
				ve[i + 1].push_back(i);
//				cout << i + 1 << ' ' << i << '\n'; 
			}
		}else{
			ve[fdlst[va[i]]].push_back(i);
//			cout << fdlst[va[i]] << ' ' << i << '\n';
		}
		fdlst[va[i]] = i;
	}
	dfs(n); 
	for (int i = 1;i <= m;i++) {
		if(i == m)cout << ans[i];
		else cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
} 
