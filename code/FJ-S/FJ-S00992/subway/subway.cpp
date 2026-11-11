#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int r = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'),c = getchar();
	return r;
}
inline void wr(long long x){
	if(!x){
		putchar('0');
		return;
	}
	static char buf[105];
	int cnt = 0;
	while(x) buf[++cnt] = (x % 10) ^ '0',x /= 10;
	while(cnt) putchar(buf[cnt--]);
}
int c,n,m,d,q;
vector<pair<int,int> > g[500005];
int a[500005];
long long w[505][505];
const long long inf = 2.0120712e18;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i <= m;i++) a[i] = read();
	for(int i = 1;i <= n;i++){
		int k = read();
		while(k--){
			int o = read();
			int t = read();
			g[o].emplace_back(i,t);
		}
	}
	memset(w,63,sizeof(w));
	for(int i = 1;i <= n;i++) w[i][i] = 0;
	for(int i = 1;i <= m;i++){
		int l = g[i].size();
		for(int j = 0;j < l;j++){
			for(int k = 0;k < l;k++){
				long long&v = w[g[i][j].first][g[i][k].first];
				v = min(v,(long long)g[i][j].second + g[i][k].second);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				w[i][j] = min(w[i][j],w[i][k] + w[k][j]);
			}
		}
	}
	while(q--){
		int x = read(),y = read();
		int l1 = g[x].size(),l2 = g[y].size();
		long long ans = inf;
		for(int i = 0;i < l1;i++){
			for(int j = 0;j < l2;j++){
				ans = min(ans,w[g[x][i].first][g[y][j].first] + g[x][i].second + g[y][j].second);
			}
		} 
		wr(ans + a[x] + a[y]);putchar('\n');
	}
	return 0;
}
