#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int MAXN = 2000005;
int c, t, n, hd, tl;
ll x[MAXN], d;
vector<int> e[MAXN];
struct Node{
	int u, dep;
};
struct Node2{
	int w, cnt;
	void clear(){
		cnt = 0;
		w = 0x3f3f3f3f;
	}
};
Node q[MAXN];
Node2 dis[MAXN];
ll read(){
	ll res = 0, op = 1;
	char ch;
	ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') op = -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return res * op;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; i++){
				x[i] = read();
			}
			ll D = x[n] - x[n - 1];
			int ct = d / D;
			if(ct <= 1) cout << '0' << '\n';
			else cout << max(0, n - 2 * ct + 1) << '\n';
		}
		return 0;
	}
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			x[i] = read();
		}
		for(int i = 1; i <= n; i++){
			e[i].clear();
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(x[j] - x[i] <= d){
					e[i].push_back(j);
				}
//				cout << i << ' ' << j << '\n';
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int i = 1; i <= n; i++){
				dis[i].clear();
			}
			hd = 1, tl = 0;
			q[++tl] = {i, 0};
			while(hd <= tl){
				int u = q[hd].u, depth = q[hd].dep;
				hd++;
//				cout << u << ' ' << depth << '\n';
				if(dis[u].w < depth) continue;
//				cout << "& " << u << ' ' << depth << '\n';
				dis[u].cnt++;
				dis[u].w = depth;
				for(int v : e[u]){
					q[++tl] = {v, depth + 1};
				}
			}
			for(int i = 1; i <= n; i++){
				if(dis[i].cnt == 2) ans++;
//				cout << dis[i].cnt << ' ';
			}
//			cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
