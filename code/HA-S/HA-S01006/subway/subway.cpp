#include<bits/stdc++.h>
#define N 505
#define M 400005

using namespace std;
int c, n, m, d, r, w[M], mp[N][M], x, st[N][M], hbh, qyz;
long long dis[N][N];
int rtnum[M], rt[M][25];

int head[N], cnt, vis[N];
struct edge{
	int nxt, to;
}e[N*N];
void add(int u, int v){
	cnt++;
	e[cnt] = {head[u], v};
	head[u] = cnt;
}

struct node{
	int pos, dist;
	bool operator <(const node &b)const{
		return dist > b.dist;
	}
};
priority_queue<node> q;
void dijkstra(int sx){
	memset(vis, 0, sizeof(vis));
	q.push({sx, 0});
	vis[sx] = 1;
	while(!q.empty()){
		node now = q.top();
		q.pop();
		int u = now.pos, v = 0;
		for(int i = head[u]; i; i = e[i].nxt){
			v = e[i].to;
			if(dis[sx][v] > dis[sx][u] + dis[u][v]){
				dis[sx][v] = dis[sx][u] + dis[u][v];
			}
			if(!vis[v]){
				q.push({v, dis[sx][v]});
				vis[v] = 1;
			}
		}
	}
}

int read(){
	int w = 1, r = 0;
	char c = getchar();
	while(c < '0' || c > '9')w = (c == '-')?(-1):(w), c = getchar();
	while(c >= '0' && c <= '9')r = (r<<3)+(r<<1)+(c^48), c = getchar();
	return r*w;
}


int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	c = read(), n = read(), m = read(), d = read(), r = read();
	for(int i = 1; i <= m; i++)w[i] = read();
	for(int i = 1; i <= n; i++){
		mp[i][0] = read();
		for(int j = 1; j <= mp[i][0]; j++){
			x = read();
			mp[i][x] = read();
			st[i][j] = x;
			rtnum[x]++;
			rt[x][rtnum[x]] = i;
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++){
		dis[i][i] = 0;
		for(int j = i+1; j <= n; j++){
			int a = i, b = j, p = 0;
			if(mp[a][0] > mp[b][0])swap(a, b);
			for(int k = 1; k <= mp[a][0]; k++){
				x = st[a][k];
				if(mp[b][x] != 0)dis[i][j] = min(dis[i][j], (long long)(mp[b][x]+mp[a][x])), p = 1;
			}
			dis[j][i] = dis[i][j];
			if(p){add(i, j); add(j, i);}
		}
	}
	for(int i = 1; i <= n; i++)dijkstra(i);
	for(int i = 1; i <= r; i++){
		hbh = read(), qyz = read();
		long long ans = 1e18;
		for(int j = 1; j <= rtnum[hbh]; j++){
			for(int k = 1; k <= rtnum[qyz]; k++){
				ans = min(ans, dis[rt[hbh][j]][rt[qyz][k]] + mp[rt[hbh][j]][hbh] + mp[rt[qyz][k]][qyz]);
			}
		}
		cout << ans + w[hbh] + w[qyz] << "\n";
	}
	return 0;
}
