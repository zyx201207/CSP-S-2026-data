#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], lst[N], ans[N];
vector<int> g[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	g[n].push_back(a[n]);ans[a[n]] ++;lst[a[n]] = n;
	for(int i = n - 1;i >= 1;i --){
		if(lst[a[i]] == 0) g[i] = g[i + 1], g[i].push_back(a[i]), lst[a[i]] = i;
		else g[i] = g[lst[a[i]]];
		for(auto j : g[i]) ans[j] ++;
	}
	for(int i = 1;i <= m;i ++) cout << ans[i] << " ";
	return 0;
}
