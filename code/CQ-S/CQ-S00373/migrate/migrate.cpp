#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5000 + 10, inf = 0x3f3f3f3f;
ll n, a[N], d;
namespace subtask1{
	ll dis[N], cnt[N], vis[N];
	int bfs(int st){
		for(int i = 1; i <= n; i++) dis[i] = inf, cnt[i] = 0, vis[i] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, st}), dis[st] = 0, cnt[st] = 1;
		while(pq.size()){
			int u = pq.top().second; pq.pop();
			if(vis[u]) continue; 
			vis[u] = true;
			for(int v = u; v <= n; v++){
				if(a[u] + d < a[v]) break;
				if(dis[u] + 1 < dis[v]) dis[v] = dis[u] + 1, cnt[v] = cnt[u], pq.push({dis[v], v});
				else if(dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
			}
		}
		int ans = 0; 
		for(int i = st; i <= n; i++){
			ans += (cnt[i] == 2);
		}
//		assert(ans -= r - l + 1);
		return ans;
	}
	void sol(){
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += bfs(i);
		cout << ans << '\n';
	}
}
void sol(){//O(n^3)
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	subtask1::sol();
//	else if(c == 13 || c == 14) subtaskB::sol(); 
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int c, T; 
	cin >> c >> T;
	while(T--) sol();
	return 0;
}
/*
0 1
5 3
-2 -1 0 1 2

T2太猎奇了，先看看 T3 
n个点在一条直线上，坐标为x_i.
如果 (i,j) 满足 |x_i - x_j| <= d 则可以从 i->j。
一条路径的长度为其经过的边数 
满足最短路恰有2条的点对(u,v)被称为好的，求满足条件的点对数。
目标是n^2
实际上跳的过程是一个dag 
先做一个 n^3 
我们先喝一口我妈带的尖叫. 
17:10 24pts
然后考虑n^2做法
n^3的瓶颈在于对于每个左端点,O(n^2\logn)求解
然后考虑维护区间 [l,r],每次移动r,然后O(1)判断该区间是否合法.
可惜的是 cnt[i]==2 的并不是一个区间 
n^3的怎么是5000啊,如果是3000我就写线段树优化建图了.
然后考虑一些特殊性质吧. 
考虑刻画合法点对的性质. 
先吃个旺仔牛b糖.
最后半个小时不看了. 
*/
