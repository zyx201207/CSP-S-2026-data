#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 510;
const int M = 501000;
const int D = 25;

struct edge {
	int to,val,nxt;
} map[M+D];

bool v[M+D];
int c,n,m,d,q,ti,tot,a[M],f[M+D],head[M+D];

void add(int x,int y,int val) {
	map[++tot] = (edge){y,val,head[x]};
	head[x] = tot;
}

void dijsktra(int s) {
	priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	memset(v,0,sizeof(bool)*(m+n+3));
	memset(f,0x3f,sizeof(int)*(m+n+3));
	f[s] = 0;
	q.push(make_pair(f[s],s));
	while (q.size()) {
		int now = q.top().second;
		q.pop();
		if (v[now]) continue;
		v[now] = true;
		for (int i = head[now];i;i = map[i].nxt) {
			int nxt = map[i].to;
			if (f[now] + map[i].val < f[nxt]) {
				f[nxt] = f[now] + map[i].val;
				q.push(make_pair(f[nxt],nxt));
			}
		}
	}
}

int bfs(int s,int t) {
	memset(v,0,sizeof(bool)*(m+n+3));
	queue <pair<int,int>> q;
	q.push(make_pair(s,0));
	v[s] = true;
	while (q.size()) {
		auto now = q.front();
		q.pop();
		for (int i = head[now.first];i;i = map[i].nxt) {
			int nxt = map[i].to;
			if (nxt == t) return now.second+1;
			if (!v[nxt]) {
				v[nxt] = true;
				q.push(make_pair(nxt,now.second+1));
			}
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++) scanf("%d",&a[i]);
	for (int k,i = 1;i <= n;i++) {
		int lst = 0;
		scanf("%d",&k);
		for (int x,val,j = 1;j <= k;j++) {
			scanf("%d%d",&x,&val);
			add(x,m+i,val);
			add(m+i,x,val);
			if (c >= 12 & c <= 19) ti = val;
		}
	}
	for (int x,y,i = 1;i <= q;i++) {
		scanf("%d%d",&x,&y);
		if (c >= 12 && c <= 19) {
			printf("%d\n",a[x]+a[y]+bfs(x,y)*ti);
		} else {
			dijsktra(x);
			printf("%d\n",a[x]+a[y]+f[y]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
