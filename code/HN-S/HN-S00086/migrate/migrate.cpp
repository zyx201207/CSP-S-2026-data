#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1, MAXK = 1e3 + 1;

int testnum, t, n, d, p[MAXN], dis[MAXK][MAXK], cnt[MAXK][MAXK];
vector<int> c[MAXN];
void bfs(int dis[], int cnt[], int st) {
	fill(dis + 1, dis + n + 1, 1e18);
	fill(cnt + 1, cnt + n + 1, 0);
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	cnt[st] = 1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = 0; i < (int)c[x].size(); i++) {
			int y = c[x][i];
			if(dis[y] > dis[x] + 1) {
				dis[y] = dis[x] + 1;
				cnt[y] = cnt[x];
				q.push(y);
			}
			else if(dis[y] == dis[x] + 1) {
				cnt[y] += cnt[x];
			}
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> testnum >> t;
	while(t--) {
		cin >> n >> d;
		p[n + 1] = 0;
		for(int i = 1; i <= n; i++) {
			c[i].clear();
			for(int j = 1; j <= n; j++) {
				dis[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				if(p[i] + d < p[j]) {
					break;
				}
				c[i].push_back(j);
				c[j].push_back(i);
			}
		}
		for(int i = 1; i <= n; i++) {
			bfs(dis[i], cnt[i], i);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
//				cout << cnt[i][j] << " ";
				if(cnt[i][j] == 2) {
					ans++;
				}
			}
//			cout << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}
//坏了不会n方
//关键是n^3log的写法还又臭又长
//2025.19.31 16:39
//终于调完了，乱七八糟转换纯史山 
//2026.10.31 16:42
//大洋里炸了 
//2026.10.31 17:12
//至今还没调出来，大洋里少输出一半 
//2025.10.31 17:42
//回归了，刚才去写T4，改半天阴成啥了
//再次入狱 
//目前准备换一种思路解决 
//2025.10.31 17:55
//这谁绷得住，搞半天想复杂了
//建个图直接就过
//懒得算时间复杂度了，给点分行不咯 

//升空对抗重力反应
//逐渐渺小的风景 景 景 景 景色分明 
//我加速引擎 抛开远方的黎明
//嘟嘟嘟嘟嘟 嘟嘟嘟嘟嘟[忘了]
//我对着流星 许愿时真心
