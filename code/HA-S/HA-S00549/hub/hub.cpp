#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5, M = 2e6 + 5;

int n, k;
int h[N], e[M], ne[M], idx;
int vis[N], dep[N], ans;
queue<int> q;

void add(int a, int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void check(){
	int sum = 0;
	while (q.size()){
		auto t = q.front();
		q.pop();
		
		for (int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if (dep[j] != -1) continue;
			dep[j] = dep[t] + 1, q.push(j);
		}
	}
	for (int i = 1; i <= n; i++) sum = max(sum, dep[i]);
	ans = min(ans, sum);
}

void dfs(int id, int k){
	if (id > n) return ;
	if (!k){
		for (int i = 1; i <= n; i++) dep[i] = -1;
		for (int i = 1; i <= n; i++){
			if (vis[i]) q.push(i), dep[i] = 0;
		}
		check();
		return ;
	}
	vis[id] = 1;
	dfs(id + 1, k - 1);
	vis[id] = 0;
	dfs(id + 1, k);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int C, T; cin >> C >> T;
	while (T--){
		memset(h, -1, sizeof h);
		idx = 0;
		
		cin >> n >> k;
		for (int i = 1; i < n; i++){
			int a, b; cin >> a >> b;
			add(a, b), add(b, a);
		}
		
		if (C <= 3){
			ans = n;
			dfs(1, k);
			cout << ans << '\n';
			continue;
		}
		else if (C == 7){
			ans = n;
			for (int i = 1; i < n; i++){
				for (int j = i + 1; j <= n; j++){
					for (int k = 1; k <= n; k++) dep[k] = -1;
					vis[i] = vis[j] = 1, dep[i] = dep[j] = 0;
					q.push(i), q.push(j);
					check();
				}
			}
			cout << ans << '\n';
			continue;
		}
		else if (C == 11 || C == 12){
			ans = n;
			for (int x = 1; x <= 500; x++){
				int i = rand() % n + 1, j = rand() % n + 1;
				if (i == j) continue;
				for (int k = 1; k <= n; k++) dep[k] = -1;
				vis[i] = vis[j] = 1, dep[i] = dep[j] = 0;
				q.push(i), q.push(j);
				check();
			}
			cout << ans << '\n';
			continue;
		}
	}
	
	return 0;
}
