#include <bits/stdc++.h>
#define en puts("")
using namespace std;

const int N = 5e3 + 6,M = 2e7 + 6;
const int inf = 1e9 + 7;

inline int rd(){
	char c;
	bool flag = 0;
	while((c = getchar()) != EOF && (c < '0' || c > '9')){
		flag = (c == '-');
	}
	int res = c - '0';
	while((c = getchar()) != EOF && (c >= '0' && c <= '9')){
		res = (res << 3) + (res << 1) + c - '0';
	}
	return flag ? -res : res;
}

inline void wr(int x){
	if (x < 0){
		putchar('-');
		wr(-x);
	}else{
		if (x > 9) wr(x / 10);
		putchar(x % 10 + '0');
	}
}

struct edge{
	int to,next;
}e[M << 1];int h[N],ecnt;

void add(int u,int v){
	e[++ecnt] = {v,h[u]};
	h[u] = ecnt;
}

int p[N],n,d;
int cnt[N],dis[N];

void dijkstra(int start){
	for (int i = 1; i <= n; ++i){
		dis[i] = inf;
		cnt[i] = 0;
	}
	queue <int> q;
	dis[start] = 0;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		++cnt[u];
		if (cnt[u] != 1) continue;
		for (int i = h[u]; i; i = e[i].next){
			int v = e[i].to;
			if (dis[v] >= dis[u] + 1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id = rd(),T = rd();
	if (id == 114514) cout << "yuanshen fenchang nb";
	while(T--){
		n = rd();d = rd();
		int ans = 0;
		for (int i = 1; i <= n; ++i){
			p[i] = rd();
		}
		sort(p + 1,p + 1 + n);
		for (int i = 1; i <= n; ++i){
			int l = i,r = i;
			while(p[i] - p[l - 1] <= d && l > 1) --l;
			while(p[r + 1] - p[i] <= d && r < n) ++r;
			for (int j = l; j <= r; ++j){
				if (i != j){
					add(i,j);
				}
			}
		}
		for (int i = 1; i <= n; ++i){
			dijkstra(i);
			for (int j = 1; j <= n; ++j){
				if (cnt[j] == 2) ++ans;
			}
		}
		wr(ans / 2);
		en;
		for (int i = 1; i <= n; ++i) h[i] = 0;
		ecnt = 0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
