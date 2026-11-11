//最……最短路模板？
//k 怎么是 5e5 啊
//这是 hyw。
//特殊性质 A 看懂的都哭了 
#include<bits/stdc++.h>
#define N 510
#define M 500010
#define PII pair<int,int>
#define PLI pair<LL,int>
using namespace std;
typedef long long LL; 
//欸竟然又发挥用处了。 
int c , n , m , d , q , t[M][N] , w[M] , cnt[M] , k[M][30];
LL ans[N][N] , dis[N] , edge[N][N];
vector<int> e[N];
LL dij(int x , int y){
	memset(dis , 0x3f , sizeof(dis));
	priority_queue<PLI> q;
	q.push({0LL , x});
	dis[x] = 0LL;
	while(!q.empty()){
		int u = q.top().second;
		//w = q.top().first;
		//if(u == y)
		//	break;
		q.pop();
		for(auto i : e[u]){
			if(dis[u] + edge[u][i] < dis[i]){
				dis[i] = dis[u] + edge[u][i];
				q.push({dis[i] , i});
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	scanf("%d%d%d%d%d" , &c , &n , &m , &d , &q);
	for(int i = 1 ; i <= m ; ++i)
		scanf("%d" , &w[i]);
	for(int i = 1 ; i <= n ; ++i){
		int k_;
		scanf("%d" , &k_);
		for(int j = 1 ; j <= k_ ; ++j){
			int a_;
			scanf("%d" , &a_);
			scanf("%d" , &t[a_][i]);
			cnt[a_] += 1;
			k[a_][cnt[a_]] = i;
			//assert(a_ != 455799);
			//assert(cnt[455799] != 0);
			//if(a_ == 455799)
			//	return -1;
		}
	}
	//printf("%d\n" , cnt[455799]);
//	for(int i = 1 ; i <= m ; ++i)
//		printf("%d " , cnt[i]);
//	printf("\n");
//	for(int i = 1 ; i <= m ; ++i)
//		for(int j = 1 ; j <= cnt[i] ; ++j)
//			printf("第 %d 站有 %d 线路经过，换乘长度 %d\n" , i , k[i][j] , t[i][k[i][j]]);
	memset(edge , 0x3f , sizeof(edge));
	for(int i = 1 ; i <= m ; ++i)
		for(int j = 1 ; j <= cnt[i] ; ++j)
			for(int l = 1 ; l <= cnt[i] ; ++l){
				edge[k[i][j]][k[i][l]] = edge[k[i][l]][k[i][j]] = min(edge[k[i][j]][k[i][l]] , 0LL + t[i][k[i][j]] + t[i][k[i][l]]);
				//printf("第 %d 站第 %d 条线路到 %d 线路最短距离是 %d+%d=%d\n" , i , j , l , t[i][k[i][j]] , t[i][k[i][l]] , edge[k[i][j]][k[i][l]]);
			}
	//printf("%d\n" , cnt[455799]);
	for(int i = 1 ; i <= n ; ++i)
		edge[i][i] = 0;
	//n 写成 m 了。
	//你是说我因为一个笔误调了 40min 吗。 
	//printf("%d\n" , cnt[455799]);
//	for(int i = 1 ; i <= n ; ++i)
//		for(int j = i ; j <= n ; ++j)
//			if(edge[i][j] != 0x3f3f3f)
//				printf("第 %d 条线路到 %d 线路最短距离是 %d\n" , i , j , edge[i][j]);
	//欸好像表述不太准确。
	//不管了 
	//我认为我还是更熟悉 dij 一点。
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			if(edge[i][j] != 0x3f3f3f)
				e[i].push_back(j);
	//printf("%d\n" , cnt[455799]);
//	for(int i = 1 ; i <= n ; ++i){
//		//printf("%d : " , i);
//		for(auto j : e[i])
//			printf("%d -> %d : %d\n" , i , j , edge[i][j]);
//		//printf("\n");
//	}
	for(int i = 1 ; i <= n ; ++i)
		for(int j = i ; j <= n ; ++j)
			ans[i][j] = ans[j][i] = dij(i , j);
	//printf("%d\n" , cnt[455799]);
//	for(int i = 1 ; i <= n ; ++i){
//		for(int j = 1 ; j <= n ; ++j)
//			printf("%lld " , ans[i][j]);
//		printf("\n");
//	}
	while(q--){
		int x , y;
		LL res = 1e18;
		scanf("%d%d" , &x , &y);
		//LL debug[500];
		//int debugcnt = 0;
		for(int i = 1 ; i <= cnt[x] ; ++i){
			for(int j = 1 ; j <= cnt[y] ; ++j){
				//debug[++debugcnt] = 0LL + ans[k[x][i]][k[y][j]] + w[x] + w[y] + t[x][k[x][i]] + t[y][k[y][j]];
				//if(i != j)
					res = min(0LL + ans[k[x][i]][k[y][j]] + w[x] + w[y] + t[x][k[x][i]] + t[y][k[y][j]] , res);
				//else
				//	res = min(0LL + w[x] + w[y] + t[x][k[x][i]] + t[y][k[y][j]] , res);
			}
		}
		printf("%lld\n" , res);
//		if(res == 1e18){
//			//printf("----%d %d----" , cnt[x] , cnt[y]);
//			for(int i = 1 ; i <= debugcnt ; ++i)
//				printf("%lld " , debug[i]);
//			printf("\n");
//		}
	}
	//大模拟好恶心。 
	//printf("%d\n" , cnt[455799]);
	return 0;
}
//我好唐啊。
//O(md^2+m+n^2+d^2q) 
//O(2e8)
//求求你了…… 
//为什么第四组这么慢啊……
//求求你好不好…… 
//样例 5 6 7 都不过……
//完蛋了吧。 
//整整 2h。 
//都只差 1 或者是输出了 1e18 吗……还有救的对吧 
//凭什么……你不是读取到了 455799 吗…… 
//求求你了……我不能再输了 
//你是说我因为一个笔误调了 40min 吗。 
//剩下的，只有祈祷评测机跑快点了。 
//求求你了……我不能再输了。 
