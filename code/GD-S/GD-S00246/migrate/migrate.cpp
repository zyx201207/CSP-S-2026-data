#include <bits/stdc++.h>
#define int long long
using namespace std;

int bfs(const vector<vector<int>> &g, int a, int u){
	vector<int> dis(a, 1LL << 60), sp(a, 0);
	queue<int> q;
	q.push(u);
	dis[u] = 0;
	sp[u] = 1;
	
	while(q.size()){
		const int i = q.front();
		q.pop();
		
		for(const auto &j : g[i])
			if(dis[j] > dis[i] + 1)
				dis[j] = dis[i] + 1,
				sp[j] = sp[i],
				q.push(j);
			else if(dis[j] == dis[i] + 1)
				sp[j] += sp[i];
	}
	
	int ans = 0;
	
	for(int i = 0; i != a; ++ i)
		if(sp[i] == 2)
			++ ans;
	
	return ans;
}

int solve(){
	int a, b;
	cin >> a >> b;
	
	vector<int> num(a);
	
	for(auto &i : num)
		cin >> i;
	
	vector<vector<int>> g(a);
	
	for(int i = 0; i != a; ++ i)
		for(int j = i + 1; j != a && num[j] <= num[i] + b; ++ j)
			g[i].push_back(j);
	
	int ans = 0;
	
	for(int i = 0; i != a; ++ i)
		ans += bfs(g, a, i);
	
	return ans;
}

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	#endif
	
	int _;
	cin >> _ >> _;
	
	while(_ --)
		cout << solve() << "\n";
	
	return 0;
}
