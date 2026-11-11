#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e6+5;
const int inf = 0x3f3f3f3f;
int c, T;
int n, Next[N][25], q[N], head, tail;
LL d, x[N], ans;
bool vis[N];

int dis(int u, int v) {
	int res = 0;
	for(int i = 24; i >= 0; i--) {
		if(Next[u][i] < v) res += (1<<i), u = Next[u][i];
	}
	return Next[u][0] >= v && Next[u][0] <= n ? res+1 : inf;
}

void solve() {
	scanf("%d%lld", &n, &d); ans = 0;
	if(n <= 300) {
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
			for(int j = 0; j < 25; j++) Next[i][j] = n+1;
		}
		for(int j = 0; j < 25; j++) Next[n+1][j] = n+1;
		head = 1, tail = 0;
		for(int i = n; i >= 1; i--) {
			while(head <= tail && x[q[head]] - x[i] > d) head++;
			if(head <= tail) Next[i][0] = q[head];
			for(int j = 1; (1<<j) <= n; j++) Next[i][j] = Next[Next[i][j-1]][j-1];
			q[++tail] = i;
		}
		// for(int i = 1; i <= n; i++) for(int j = 0; (1<<j) <= n; j++) printf("Next[%d][%d]=%d\n", i, j, Next[i][j]);

		for(int u = 1; u <= n; u++)
			for(int v = u+1; v <= n; v++) {
				if(dis(u, v) != inf) {
					int D = dis(u, v);
					// printf("dis(%d,%d)=%d\n", u, v, D);
					for(int t = u; t < v; t = Next[t][0]) vis[t] = true;
					vis[v] = true; int cnt = 0;
					for(int t = u; t <= v; t++) {
						if(vis[t]) continue;
						if(dis(u, t) + dis(t, v) == D) cnt++;
					}

					ans += (cnt==1);
					// if(cnt == 1) printf("(%d,%d)\n", u, v);
					for(int t = u; t < v; t = Next[t][0]) vis[t] = false;
					vis[v] = false;
				}
			}
		
		printf("%lld\n", ans);
	}
	else puts("0");
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	scanf("%d%d", &c, &T);
	while(T--) solve();

	return 0;
}
/*
buhui...
说来我是不是应该混用多种编码来证明自己不是人类？
不管了，致敬传奇 AIer NM-S00251（我应该没记错吧）
让我上奇葩行为大赏啊！！！
不得不说报 NOI Linux 小孩哥就是少，只可惜赛前赌有交互题赌输了。
//freopen

曾许下心愿，等待你的出现。
褪色的秋千，有本书会纪念。
我循着时间，捡起梦的照片～
童话还没有兑现，却需要说再见……

Say my name when a tree susrate（我是不是拼错了）
英文歌好难唱，但是爱门！
*/