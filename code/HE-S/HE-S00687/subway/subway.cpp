#include<bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 10;
long long c, n, m, d, q; 
long long w[N];
long long a[N];
long long t[N];
long long jl[N][N];

struct node{
	long long to, v;
};vector<node> b[N];
node add_node(long long a, long long b){
	node ans;
	ans.to = a; ans.v = b;
	return ans;
}
long long vis[N];
long long minn[N];
queue<long long> s;
long long spfa(long long x, long long y){
	while (!s.empty()){
		s.pop();
	}
	memset(vis, 0, sizeof(vis));
	memset(minn, 0x3f, sizeof(minn));
	minn[x] = 0;
	s.push(x);
	vis[x] = 1;
	while (!s.empty()){
		long long now = s.front();
		s.pop(); vis[now] = 0;
		for (long long i = 0; i < b[now].size(); i++){
			long long to = b[now][i].to;
			if (to == now){
				continue;
			}
			long long len_th = b[now][i].v;
			if (minn[now] + len_th < minn[to]){
				minn[to] = minn[now] + len_th;
				if (vis[to] == 0){
					s.push(to);
					vis[to] = 1;
				} 
			}
		}
	}
	for (int i = 1; i <= m; i++){
		jl[x][i] = minn[i];
	}
	return minn[y];	
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (long long i = 1; i <= n; i++){
		long long k;
		cin >> k;
		for (long long j = 1; j <= k; j++){
			cin >> a[j] >> t[j];
			if (j >= 2){
				b[a[j]].push_back(add_node(a[j - 1], t[j] + t[j - 1]));
				b[a[j - 1]].push_back(add_node(a[j], t[j] + t[j - 1]));
			}
		}
	} 
	for (long long i = 1; i <= q; i++){
		long long x, y;
		cin >> x >> y;
		if (jl[x][y] != 0){
			cout << jl[x][y] + w[x] + w[y];
			continue; 
		}
		cout << spfa(x, y) + w[x] + w[y] << endl;
	}
	return 0;
}
