#include <bits/stdc++.h>
#define mkp(x,y) make_pair(x,y)
#define int long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while (!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return ;
	}
	if (x < 10){
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
int c,n,m,d,q;
vector <pair <int,int> > sub[500050];
int w[500050];
int g[550][550],f[550][550];
vector <pair <int,int> > plat[500050];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1;i <= m;i++) w[i] = read();
	for (int i = 1;i <= n;i++){
		int k = read();
		for (int j = 1;j <= k;j++){
			int a,t;
			a = read(),t = read();
			sub[i].push_back(mkp(a,t));
			plat[a].push_back(mkp(i,t));
		}
	}
	memset(g,0x3f,sizeof(g));
	for (int i = 1;i <= m;i++){
		for (int j = 0;j < plat[i].size();j++){
			for (int k = j + 1;k < plat[i].size();k++){
				int u = plat[i][j].first,v = plat[i][k].first,w = plat[i][j].second + plat[i][k].second;
				g[u][v] = min(g[u][v],w);
				g[v][u] = min(g[v][u],w);
			}
		}
	}
	for (int i = 1;i <= n;i++) f[i][i] = 0;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			if (i == j) continue;
			f[i][j] = g[i][j];
		}
	}
	for (int k = 1;k <= n;k++) for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	while (q--){
		int x,y;
		x = read(),y = read();
		int ans = 114514191981000001;
		for (int i = 0;i < plat[x].size();i++) for (int j = 0;j < plat[y].size();j++) ans = min(ans,f[plat[x][i].first][plat[y][j].first] + plat[x][i].second + plat[y][j].second);
		write(ans + w[x] + w[y]),putchar('\n');
	}
	return 0;
}