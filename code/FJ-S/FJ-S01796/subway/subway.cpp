#include <bits/stdc++.h>
using namespace std;

int w[500010],t[510][500010],nxt[500010][3],vis[510];
long long shortest;
int c,n,m,d,q,stop,u,v;

void dfs(int now,int to,long long dis){
	if (now == to){
		if (dis < shortest) shortest = dis;
		return;
	}
	if (dis >= shortest) return;
	for (int i = 1;i <= m;i++){
		if (t[now][i] != 0){
			if (nxt[i][1] == now) dfs(nxt[i][2],to,dis + t[now][i]);
			else dfs(nxt[i][1],to,dis + t[now][i]);
		}
	}
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= n;i++) cin >> w[i];
	for (int i = 1;i <= m;i++){
		cin >> stop;
		for (int j = 1;j <= stop;j++){
			cin >> u;
			cin >> t[u][i];
			nxt[i][j] = u;
		}
	}
	for (int i = 1;i <= q;i++){
		cin >> u >> v;
		time = w[u] + w[v];
		shortest = 1e8;
		dfs(u,v,0);
		cout << shortest << endl;
	}
	return 0;
}
