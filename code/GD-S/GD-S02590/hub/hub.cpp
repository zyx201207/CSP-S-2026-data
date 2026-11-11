#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
/*

*/
typedef long long ll;
const int N = 2e6 + 5;
int n, k, tp, ans = 1e7, sum;
int head[N], nxt[N << 1], to[N << 1];
bool book[N], vis[N];
queue<pair<int, int> > q;
inline void add(int a, int b){
	nxt[++tp] = head[a];
	to[tp] = b;
	head[a] = tp;
	return ;
}
void dfs2(int id, int fa){
//	printf("dfs2 : %d\n", id);
	for(int i = head[id], t; i; i = nxt[i]){
		t = to[i];
		if(t != fa){
			dfs2(t, id);
		}
	}
	if(book[id] && (fa == -1 || !book[fa])){
		++sum;
	}
	return ;
}
int dist(int st){
	if(book[st]){
		return 0;
	}
	while(!q.empty()){
		q.pop();
	}
	q.push(mp(st, 0));
	for(int i = 1; i <= n; ++i){
		vis[i] = false;
	}
	int id, d;
	while(!q.empty()){
		id = q.front().first;
		d = q.front().second;
		q.pop();
		vis[id] = true;
//		printf("bfs : %d\n", id);
		for(int i = head[id], t; i; i = nxt[i]){
			t = to[i];
			if(!vis[t]){
				if(book[t]){
					return d + 1;
				}
				else{
					q.push(mp(t, d + 1));
				}
			}
		}
	}
	return 0;
}
void dfs1(int id, int cnt){
	if(cnt > k){
		return ;
	}
	if(id > n){
		if(cnt < k){
			return ;
		}
		sum = 0;//Á¬Í¨¿é 
		dfs2(1, -1);
//		printf("11111111111\n");
		if(sum <= 2){
			int res = 0;
			for(int i = 1; i <= n; ++i){
//				printf("dist[%d] : ...\n", i);
				res = max(res, dist(i));
			}
			ans = min(ans, res);
		}
		return ;
	}
	book[id] = false;
	dfs1(id + 1, cnt);
	book[id] = true;
	dfs1(id + 1, cnt + 1);
	return ;
}
void solve(){
	cin >> n >> k;
	tp = 0;
	memset(head, 0, 4 * n + 8);
	for(int i = 1, a, b; i < n; ++i){
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	ans = 1e7;
	dfs1(1, 0);
	cout << ans << '\n';
	return ;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cc, _;
	cin >> cc >> _;
	while(_--){
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/
