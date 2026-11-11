#include<bits/stdc++.h>
using namespace std;
struct node {
	map<int , long long> s;
};
vector<node> edge(505);
long long c , n , m , d , q;
long long w[500005];
bool vis[500005];
long long dfs(long long x , long long y , long long sum) {
	if(x == y) {
		return sum;
	}
	long long ans = 9999999999999999;
	bool k = 0;
	for(int i = 1; i <= n; i++) {
		if(edge[i].s[x] != 0) {
			sum += edge[i].s[x];
			for(auto j : edge[i].s)
				if(vis[j.first] == 0) {
					k = 1;
					vis[j.first] = 1 , sum += j.second;
					ans = min(ans , dfs(j.first , y , sum));
					vis[j.first] = 0 , sum -= j.second;
				}
			sum -= edge[i].s[x];
		}
	} 
	if(k == 1) return ans;
	return 9999999999999999;
}
void work() {
	long long x , y;
	cin >> x >> y;
	memset(vis , 0 , sizeof(vis));
	vis[x] = 1;
	long long sum = dfs(x , y , w[x] + w[y]);
	cout << sum << "\n";
}
int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			long long a , b;
			cin >> a >> b;
			edge[i].s[a] = b;
		}
	}
	while(q--) {
		work();
	} 
	return 0;
}
