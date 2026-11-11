#include<bits/stdc++.h>
#define int long long
using namespace std;
int l[500005]; 				//l[i]是编号为i站台经过的线路数  
struct node{
	int num, t;
}dao[500005][25];	//dao[i][j]是第j个经过编号i站点的线路 
vector <node> b[505];
struct yy{
	int to, next, len;
}road[505 * 505];
int cnt, head[505];
void add(int x, int y, int le){
	road[++cnt].next = head[x];
	road[cnt].to = y;
	road[cnt].len = le;
	head[x] = cnt;
}
queue <int> q;
bool vis[505];
int f[505][505];
void dj(int sta){				//spfa(dj忘记了) 
	memset(vis, 0, sizeof(vis));
	q.push(sta);
	vis[sta] = 1;
	f[sta][sta] = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		vis[now] = 0;
		for(int i = head[now];i;i = road[i].next){
			int r = road[i].to;
			if(f[sta][r] > f[sta][now] + road[i].len){
				f[sta][r] = f[sta][now] + road[i].len;
				if(!vis[r])
					q.push(r), vis[r] = 1;
			}
		}
	}
}
int n, m, c, d, qq, w[500005], k[505], ll[505][505];
int numb, ti, x, y, ans;
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> numb >> ti;
			b[i].push_back({numb, ti});
			dao[numb][++l[numb]] = {i, ti};
		}
	} 
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)ll[i][j] = LONG_LONG_MAX - 1;
	for(int i = 1;i <= n;i++)				//遍历线路 
		for(int j = 1;j <= k[i];j++){		//遍历线路中的地铁站 
			int now = b[i][j].num; 			//now是当前遍历的地铁站 
			for(int k = 1;k <= l[now];k++){
				int to = dao[now][k].num;		//to是连接的地铁站
				if(dao[now][k].num != i){		//不同的线路 
					ll[dao[now][k].num][i] = min(ll[dao[now][k].num][i], dao[now][k].t + b[i][j].t);
					ll[i][dao[now][k].num] = min(ll[i][dao[now][k].num], dao[now][k].t + b[i][j].t); //先存起来，方便去重 
				}
			}
		}
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			if(ll[i][j] != LONG_LONG_MAX - 1){
				add(i, j, ll[i][j]);
				add(j ,i, ll[i][j]);		//建双向边 
			}
	memset(f, 63, sizeof(f));
	for(int i = 1;i <= n;i++) dj(i);			//开始最短路 
	for(int i = 1;i <= qq;i++){
		cin >> x >> y;
		ans = LONG_LONG_MAX - 1;
		for(int j = 1;j <= l[x];j++)
			for(int k = 1;k <= l[y];k++)ans = min(ans, w[x] + w[y] + dao[x][j].t + dao[y][k].t + f[dao[x][j].num][dao[y][k].num]);
		cout << ans << '\n';
	}
	return 0;
}
/*
500条地铁线路
5*10^5个站
每个站不会被超过20条线路经过
考虑将线路看作点
遍历这个‘点’中所有地铁站
将能通过任一地铁站中转的线路建边
最后跑n遍dj即可求得任意两线路间距离
在询问时遍历地铁站经过线路即‘点’， 取最小值即可 
*/

