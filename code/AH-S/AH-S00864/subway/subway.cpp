#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5E5+5,M = 505;
LL c, n, m, d, q, w[N],k[N],A,T, x,y,mi=INT_MAX;
struct node {
	LL to, ti;
	bool operator < (const node &rhx) const {
		return to<rhx.to;
	}
};
vector<node> p[N];
bool vis[N], vish[N];
void dfs(int x, int y, LL dis) {
	if (dis>mi) return;
	if (x == y) {
		mi = dis;
		return ;
	}
	for (int i = 1; i <= n; i ++){
		int l = 1, r = k[i],id = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (p[i][mid].to == x) {
				id = mid;
				break;
			} else if (p[i][mid].to > x) r = mid - 1;
			else l= mid+1;
		}
		if (id == -1) continue;
		LL pos = p[i][id].ti;
		for (int j = 1; j <= k[i];j ++) {
			if (p[i][j].to==x) continue;
			if (!vis[p[i][j].to]) {
				vis[p[i][j].to] = true;
				dfs(p[i][j].to, y, dis + pos + p[i][j].ti);
				vis[p[i][j].to] = false;
			}
		}
	}
}
int main() {
	freopen("subway.in","r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i],p[i].push_back({(LL)0, (LL)0});
		for (int j = 1; j <= k[i]; j++) {
			cin>>A >> T;
			p[i].push_back({A,T});
		}
	}
	bool ok = true;
	for (int i = 1; i <= n; i ++)
		if (k[i] > 2) {
			ok = false;
			break;
		}
	while (q--) {
		cin >>x>>y,mi = INT_MAX;
		if (ok){
			for (int i = 1; i <= n; i ++) {
				bool OK = false;
				int ID;
				for (int j = 1; j <= k[i]; j ++) {
					if (p[i][j].to == x){
						OK = true, ID = j;
						break;
					}
				}
				if (!OK) continue;
				memset (vis,false,sizeof vis), vis[x]= true;
				memset (vish,false,sizeof vish), vis[i]=true;
				int id= x, h=i;
				LL res = p[i][ID].ti;
				while (id !=y) {
					vish[h] = true;
					for (int j = 1; j <= k[h]; j++){
						if (!vis[p[i][j].to]) {
							vis[p[i][j].to]= true;
							res += p[i][j].ti, id = p[i][j].to;
						}
					}
					for (int I = 1; I <= n; I ++) {
						if (vish[I]) continue;
						int l = 1, r = n;
						while (l <=r) {
							int mid = (l + r) >> 1;
							if (p[I][mid].to == id){
								h=I,res += p[I][mid].ti;
								break;
							}
						}
					}
				}
				mi = min(mi, res + w[x] + w[y]);
			}
			cout << mi << '\n';
		} else {
			memset (vis,false,sizeof vis), vis[x]= true;
			dfs(x,y,(LL)0),cout << mi+w[x]+w[y]<< '\n';
		}
	}
	return 0;
}
