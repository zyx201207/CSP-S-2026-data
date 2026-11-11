#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

const int N = 2e6 + 5;

int C, T, n, a[N], d, ans, b[N];
vector<int> g[5005];

bool flagA = 1;

void init(){
	for(int i = 1 ; i <= 5000 ; i ++){
		g[i].clear();
		b[i] = 1e9;
	}
	ans = 0;
}

bool bfs(int s, int t){
	int cur = n + 1, cnt = 0;
	b[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u = q.front();
		q.pop();
		if(u == t){
			cnt ++;
			if(cnt == 1) cur = b[u];
		}
		if(b[u] >= cur) continue;
		for(int i = 0 ; i < g[u].size() ; i ++){
			int v = g[u][i];
			if(b[v] >= b[u] + 1){
				b[v] = b[u] + 1;
				q.push(v);
			}
		}
	}
	return cnt == 2;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin >> C >> T;
	while(T --){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i];
		}
		if(n <= 5000){	
			init();
			for(int i = 1 ; i <= n ; i ++){
				for(int j = i + 1 ; j <= n ; j ++){
					if(abs(a[i] - a[j]) <= d){
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
			for(int i = 1 ; i <= n ; i ++){
				for(int j = i + 1 ; j <= n ; j ++){
					if(bfs(i, j)){
						ans ++;
					}
				}
			}
			cout << ans << '\n';
		}
		else if(a[2] - a[1] == a[3] - a[2]){
			int dif = d / (a[2] - a[1]);
			if(dif <= 1 || 2 * dif > n){
				cout << "0\n";
			}
			else{
				cout << n - 2 * dif + 1 << '\n';
			}
		}
		else{
			int m = 0;
			if(n % 2){
				m = n / 2 + 1;
			}
			else{
				m = n / 2;
				if(a[m] - a[1] > d || a[n] - a[m] > d) m ++; 
			}
			int ans = m * (m - 1) / 2;
			for(int l = 1, r = m + 1 ; r <= n ; r ++){
				while(a[r] - a[l] > d) l ++;
				ans += (r - l);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
//你多变的表情 
//此设备的所有者已关闭恐龙游戏。nooooooooo
