//本题青题吗？还是蓝题，应该是蓝，不是蓝的话就很危险了，今年分数线可能上200！ 
//24分做法：求出每个岛屿向右走能到达的最远岛屿，最短路就是每次贪心的取最远的走，bfs即可
//其实40分也可以bfs，现在悲观220分，广东省应该1=了吧...，我不太想写了，但是还有2个小时，继续想吧 
//显然最短路一定是朝着一个方向去，我们假定是从坐标小的岛屿到坐标大的岛屿去的 

//特殊性质A表示除了边界，那么其它点可以到达的点的数量是固定的
//特殊性质N 
//本题n的大小几乎锁死了O(nlogn)或者O(n)，因为大多数的STL都是做不到
//显然一个点与当前点有双径岛屿对的话那么它的路径肯定有第一远和第二远能到达且排除掉第三远能到达的公共位置
//算了先写暴力吧，时间不多了 
#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
#define int long long
#define File(x) freopen(x".in" , "r" , stdin);freopen(x".out" , "w" , stdout)
int n , d;
int a[N];//to_i表示第i个岛屿可以到达[to_i , i - 1] 
vector<int> Next[N];
int r[N];
int step[N] , way[N];
void bfs(int s){
	bitset<N> vis;
	memset(step , 0x3f , sizeof(step));
	memset(way , 0 , sizeof(way));
	way[s] = 1;
	vis[s] = 1;
	queue<int> qu;
	qu.push(s);
	while(!qu.empty()){
		int t = qu.front();
		qu.pop();
		for(auto i : Next[t]){
			if(step[i] == step[t] + 1){
				way[i] += way[t];
			}
			if(vis[i] == 0){
//				printf("form %lld to %lld , the way it %lld\n" , t , i , way[i]);
				vis[i] = 1;
				way[i] = way[t];
				step[i] = step[t] + 1;
				qu.push(i);
			} 
		}
	}
}
signed main(){
//	freopen("migrate3.in" , "r" , stdin);
	File("migrate");
//	freopen("myans3.out" , "w" , stdout);
	int c , t;
	scanf("%lld %lld" , &c , &t);
	while(t --){
		scanf("%lld %lld" , &n , &d);
		for(int i = 1;i <= n;i ++){
			scanf("%lld" , a + i);
			Next[i].clear();
		}	
		a[0] = -0x3f3f3f3f3f3f3f3f;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= n;j ++){
				if(i == j) continue;
				if(a[i] - a[j] <= d){
					Next[i].push_back(j);
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			bfs(i);
			for(int j = 1;j <= n;j ++){
//				printf("%lld " , way[j]);
				if(way[j] == 2) ans ++;
			}
//			puts("");
		}
		printf("%lld\n" , ans);
		//我们猜测代码实现一定是从左到右的，因为边是往左走，所以为了能处理后面的数我们选择该遍历顺序 	
	}
	return 0;
}
//期望估分：100+80+40=220（经过我认真第猜测，应该是100+92+40=232	），足够S1=?要是可以其 
