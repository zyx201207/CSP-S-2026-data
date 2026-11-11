//GZ-S00308 贵阳市第十七中学 徐廷蔚 
/*T2大意：
给定m个地铁站。
地铁站v从地铁口到站厅花费w[v]的代价
给定n条地铁线路。
第i条线路经过k[i]个地铁站，它们的编号依次为a[i][1]...a[i][k[i]]
	在第a[i][j] (1<=j<=k[i])个地铁站处，
	从站厅走到第i条线路的站台需要t[i][j]的时间。
每个地铁站最多有d条线路经过,图联通.

q个出行计划。
对于第r(1<=r<=q)个出行计划
从第x[r]个地铁站的地铁口出发，乘坐地铁到达第y[r]个地铁站的地铁口
中途可能换乘。
换乘:从一条线路的站台先走到站厅，再从站厅走到另一条线路的站台。
分析换乘的时间花费（从第s个地铁站的u线到v线）
设第s个地铁站在u线的第su位，在v线的第sv位 
	t[u][su] + t[v][sv]
分析：总步行时间为进出站和换乘的步行时间之和
假设从fs号线上(x[r]在这条线路上的位置为px)，从lt(py)号线下
	w[x[r]] + t[fs][px]  + w[y[r]] + t[lt][py] + (所有换乘) 
	求上式min，即为求(所有换乘)之min.
*/
/*0分BFS：
	3.BFS求路线：
	queue里面先放x[r]所在位置的所有线路
	node:当前点now,上一个点la,当前线路p,当前花费cost.
	TODO*/ 
/*思路：
1.求每个站点i从u号线换到v号线的时间，存在trans[i][u][v]中.O(nd^2)
2.求每个站点里有哪些线路经过vector<int>V[n+1]，这个从大到小排序。 

4.统计出每两条线路之间的换乘最小代价Min[u][v],-1表示没有直接换乘点
利用这个矩阵BFS
queue Q node:当前所在线路now,当前总花费cost
初始化：x[r]上所有线路的放入，同时把开始定值部分加上。 
扩展：node u = Q.front;
	Q.pop()
	若y[r]中没有u： 
		把所有Min[u][v] != -1的v放入，同时new_cost = u.cost + Min[u][v] 
	若有：
		更新答案 ans = min(ans,u.cost + 结束定值) 
		退出。 
vis数组，作用是把所有过y[r]站点的线路都标记出来。 */
#include<bits/stdc++.h>
using namespace std;
const int M = 500005;
const int N = 505;
int TEST_INDEX,n,m,d,q;
int w[M],k[N];
int a[N][N];
int t[N][N];
int x[100005],y[100005];
struct HuanCheng {
	int xianlu,xuhao;
};
struct Node{
	long long cost;
	int now;
};
bool cmp(HuanCheng a,HuanCheng b) {
	return a.xianlu < b.xianlu;
}
vector<HuanCheng>V[M];
long long Min[N][N];
bool visd[N];
bool vis[N];
long long dis[N];
int main() {
	fropen("subway.in","r",stdin);
	fropen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&TEST_INDEX,&n,&m,&d,&q);
	for(int i = 1;i <= m;i ++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i ++) {
		scanf("%d",k[i]);
		for(int j = 1;j <= k[i];j ++) {
			scanf("%d%d",&a[i][j],&t[i][j]);
			V[a[i][j]].push_back({i,j}); 
		}
	}
	for(int i = 1;i <= q;i ++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i = 1;i <= m;i ++) sort(V[i].begin(),V[i].end(),cmp);
	//求每个站点i从u号线换到v号线的时间,
	//统计出每两条线路之间的换乘最小代价Min[u][v]
	memset(Min,-1,sizeof Min);
	for(int i = 1;i <= n;i ++) Min[i][i] = 0;
	for(int i = 1;i <= m;i ++) {
		for(int idu = 0;idu < V[i].size();idu ++) {
			for(int idv = idu + 1;idv < V[i].size();idv ++) {
				int u = V[i][idu].xianlu;
				int v = V[i][idv].xianlu;
				int su = V[i][idu].xuhao;
				int sv = V[i][idv].xuhao;
				//设第s个地铁站在u线的第su位，在v线的第sv位 
				//t[u][su] + t[v][sv]
				if(Min[u][v] == -1) Min[u][v] = (long long)t[u][su] + (long long)t[v][sv];
				Min[u][v] = min(Min[u][v],(long long)t[u][su] + (long long)t[v][sv]);
				Min[v][u] = Min[u][v];
			}
		}
	}
	/*queue Q node:当前所在线路now,当前总花费cost
	初始化：x[r]上所有线路的放入，同时把开始定值部分加上。 
	扩展：node u = Q.front;
	Q.pop()
	若y[r]中没有u(通过vis判断)： 
		把所有Min[u][v] != -1的v放入，同时new_cost = u.cost + Min[u][v] 
	若有：
		更新答案 ans = min(ans,u.cost + 结束定值) 
		退出。*/
	/*从fs号线上(x[r]在这条线路上的位置为px)，从lt(py)号线下
	   w[x[r]] + t[fs][px]  + w[y[r]] + t[lt][py] + (所有换乘) */
	for(int hwzfjykwm = 1;hwzfjykwm <= q;hwzfjykwm ++) {
		//对于每一个起点，跑一次dijkstra 
		queue<Node>Q;
		long long ans = 0x3f3f3f3f3f3f3f3f;
//		queue<Node>Q;
//		//初始化Q
		//初始化vis
		int r = hwzfjykwm;
		for(int i = 1;i <= m;i ++) vis[i] = 0;
		for(int i = 0;i < V[y[r]].size();i ++) vis[V[y[r]][i].xianlu] = 1;
		for(int i = 0;i < V[x[r]].size();i ++) {
			Node add = {0,0};
			add.now = V[x[hwzfjykwm]][i].xianlu;
			add.cost = w[x[hwzfjykwm]] + t[add.now][V[x[hwzfjykwm]][i].xuhao];
			Q.push(add);
			memset(dis,0x3f,sizeof dis);
			memset(visd,0,sizeof visd);
			dis[add.now] = 0;
			visd[add.now] = 1;
			while(Q.size()) {
				Node tmp = Q.front();
				int u = tmp.now;
				long long cnow = tmp.cost;
				visd[u] = 0;
				Q.pop();
				if(!vis[u]) {
					long long minn = 0x3f3f3f3f3f3f3f3f;
					int minn_id = -1;
					for(int v = 1;v <= n;v ++) {
						if(v!=u && Min[u][v] + dis[u] < dis[v]) {
							dis[v] = Min[u][v] + dis[u];
							visd[v] = 1;
//							Q.push({v,dis[v]});
						}
						if(minn > dis[v]) {
							minn_id = v;
						}
					}
					if(!visd[minn_id]) {
						visd[minn_id] = 1;
						Q.push({minn,minn_id});
					}
				} else {
					ans = min(ans,dis[u] + w[y[hwzfjykwm]] + t[u][V[y[hwzfjykwm]][i].xuhao]);
					continue;
				}
			}
		} 
//		while(Q.size()) {
//			Node tmp = Q.front();
//			int u = tmp.now;
//			long long cnow = tmp.cost;
//			Q.pop();
//			if(!vis[u]) {
//				for(int v = 1;v <= n;v ++) {
//					if(Min[])
//				}
//			} else {
//				
//			}
//		}
		cout << ans;
	}

	return 0;
}
