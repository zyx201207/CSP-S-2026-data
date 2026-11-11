#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int bh,t,n,k,ans = 1e9,a[1000005],d[1000005],maxn,b[1005][1005];
vector <int> g[1000005];
bool f;

void bfs() {
	memset(d,63,sizeof d);
	priority_queue <pii,vector <pii>,greater <pii>> q;
	for (int i = 1;i <= k;i++) 
		q.push({0,a[i]}),d[a[i]] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		if (q.top().first > ans) return ;
		q.pop();
		for (int y:g[x]) 
			if (d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				q.push({d[y],y});
			}
	}
}

void dfs(int pos,int st,int ltk) {
	if (ltk > 2) return ;
	if (pos - 1 == k) {
		bfs();
		maxn = 0;
		for (int i = 1;i <= n;i++) maxn = max(maxn,d[i]);
		ans = min(ans,maxn);
	}
	for (int i = st;i <= n;i++) {
		a[pos] = i;
		f = 0;
		for (int j = 1;j < pos;j++) 
			if (b[a[j]][i]) {
				f = 1;
				dfs(pos + 1,i + 1,ltk);
				break;
			}
		if (!f) dfs(pos + 1,i + 1,ltk + 1);
	}
}

int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&bh,&t);
	while (t--) {
		scanf("%d%d",&n,&k);
		for (int i = 1;i <= n;i++) g[i].clear();
		for (int i = 1;i <= n;i++) 
			for (int j = 1;j <= n;j++) b[i][j] = 0;
		for (int i = 1,x,y;i < n;i++) {
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
			b[x][y] = b[y][x] = 1;
		}
		ans = 1e9;
		dfs(1,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
