#include<bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
int c, T;
int n, k, fa[N], ans, d[N];
vector<int> G[N];

int Find(int u) {return fa[u] = u==fa[u] ? u : Find(fa[u]);}
void Merge(int u, int v) {fa[Find(u)] = Find(v);}

bool check(int base, int u) {
	return (base>>(u-1))&1;
}

int bfs(int base, int st) {
	queue<int> q;
	for(int i = 1; i <= n; i++) d[i] = -1;
	d[st] = 0; q.push(st);

	while(!q.empty()) {
		int u = q.front(); q.pop();

		for(int v : G[u]) {
			if(d[v] != -1) continue;
			d[v] = d[u]+1;
			if(check(base, v)) return d[v];
			q.push(v);
		}
	}
}

int calc(int base) {
	int res = 0;
	for(int u = 1; u <= n; u++) {
		if(check(base, u)) continue;
		res = max(res, bfs(base, u));
	}
	return res;
}

void solve() {
	scanf("%d%d", &n, &k); ans = inf;
	for(int i = 1; i <= n; i++) {
		G[i].clear(); G[i].shrink_to_fit();
	}

	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v); G[v].push_back(u);
	}

	for(int base = 0; base < (1<<n); base++) {
		if(__builtin_popcount(base) != k) continue;
		for(int i = 1; i <= n; i++) fa[i] = i;
		int cnt = k;
		for(int u = 1; u <= n; u++) {
			if(!check(base, u)) continue;
			for(int v : G[u]) if(check(base, v) && Find(v) != Find(u)) {
				Merge(u, v);
				cnt--;
			}
		}
		if(cnt > 2) continue;
		ans = min(ans, calc(base));
	}

	printf("%d\n", ans);
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	scanf("%d%d", &c, &T);
	while(T--) solve();

	return 0;
}
/*
如果你看到这了，我可以告诉你一个惊喜。
中间忘了。
反正也没人看这段话，因为是机器判题。
//freopen
//freeopen
hud.in
freopen("hub.in", "w", stdin);
fclose(stdin)
fclose(stdout)
Luogu @aaa1145141919810 uid:1360556
理论上我在这画一只米老鼠是不是被最强法务部找到并端上奇葩行为大赏概率更大。
  __    __
 /  \  /  \
 \__/__\__/
 /        \
 |   |  |  |
 |     >   |   怎么画成史莱姆了，算了就这样吧。
 \________/

 为什么我费时费力认真整活不如小孩哥们以及天才的灵机一动，完全没有灵感。
 什么叫我 30min 切 T1 T2 但是剩下 3.5h 只拼了 T3 T4 32+15=47pts？？？
 感觉钩 7 没了。
*/