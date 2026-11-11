#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505,N = 5e5+5,M = 1e3+5,INF = 1e10+5;
int c,n,m,d,q,len;
int x[M],t[M][M];
int w[N];//地铁口到站厅的耗时 
struct node{
	int point,ti,line;
};
vector<node> g[M];
int mp[M][M];
int l,r;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++) mp[i][j] = INF;
	}
	for(int o = 1;o <= n;o++){
		cin >> len;
		for(int i = 1;i <= len;i++){
			cin >> x[i];
			cin >> t[o][x[i]];
//			scanf("%lld %lld",&x[i],&t[o][x[i]]);
		}
		for(int i = 1;i <= len;i++){
			for(int j = 1;j <= len;j++){
				if(i == j) continue;
				mp[x[i]][x[j]] = min(t[o][x[j]] + t[o][x[i]],mp[x[i]][x[j]]);
				for(int ter = 0;ter < g[x[i]].size();ter++){
//					if(g[x[i]][ter].ti != t[g[x[i]][ter].line][x[i]]) cout << "ohno\n";
					mp[x[j]][g[x[i]][ter].point] = min(mp[x[j]][g[x[i]][ter].point],t[o][x[j]] + t[o][x[i]] + t[g[x[i]][ter].line][x[i]] + g[x[i]][ter].ti);
					mp[g[x[i]][ter].point][x[j]] = min(mp[g[x[i]][ter].point][x[j]],t[o][x[j]] + t[o][x[i]] + t[g[x[i]][ter].line][x[i]] + g[x[i]][ter].ti);
				}
				g[x[i]].push_back({x[j],t[o][x[j]],o});
			}
		}
	}
//		for(int i = 1;i <= m;i++){
//			for(int j = 1;j <= g[i].size();j++){
//				mp[i][g[i][j].point] = min(t[o][g[i][j].point] + t[o][i],mp[i][g[i][j].point]);
//				for(int ter = 0;ter < g[i].size();ter++){
////					if(g[i][ter].ti != t[g[i][ter].line][i]) cout << "ohno\n";
//					mp[g[i][j].point][g[i][ter].point] = min(mp[g[i][j].point][g[i][ter].point],t[o][g[i][j].point] + t[o][i] + t[g[i][ter].line][i] + g[i][ter].ti);
//					mp[g[i][ter].point][g[i][j].point] = min(mp[g[i][ter].point][g[i][j].point],t[o][g[i][j].point] + t[o][i] + t[g[i][ter].line][i] + g[i][ter].ti);
//				}
//			}
//		}
	for(int i = 1;i <= q;i++){
		cin >> l >> r;
		cout << mp[l][r] + w[l] + w[r] << "\n";
	}
	return 0;
}
