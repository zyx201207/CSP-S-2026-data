/*
迁徙（migrate）
【题目描述】
海上有 n 座岛屿，自北向南排成一条直线，其中第 i (1 ≤ i ≤ n) 座岛屿在这条直
线上的坐标为整数 xi，且 x1 < x2 < · · · < xn。每年秋季，一群海鸟会沿着这条直线在
南北方向上迁徙，小 P 正在观察它们。
海鸟的体力有限，每次飞行的距离都不超过 d。若两座岛屿 i, j (1 ≤ i, j ≤ n) 满足
|xi-xj| ≤ d，海鸟就可以从第 i 座岛屿直接飞到第 j 座岛屿。
对于两座不同的岛屿 u, v (1 ≤ u, v ≤ n)，一条从第 u 座岛屿到第 v 座岛屿的路径
形如 y1 → y2 → · · · → ym，其中 y1 = u，ym = v，且对于所有 l (1 ≤ l ≤ m-1)，海鸟
都能够从第 yl 座岛屿直接飞到第 yl+1 座岛屿；其长度为 m - 1，即海鸟在路径中飞行
的次数。
小 P 发现，海鸟在迁徙时总是会选择长度最短的路径。对于两座岛屿 u, v (1 ≤ u <
v ≤ n)，若从第 u 座岛屿到第 v 座岛屿的长度最短的路径恰. 好. 有两条，海鸟可以分成两
群，分别沿其中一条飞往第 v 座岛屿；此时称 (u, v) 为双. 径. 岛. 屿. 对. 。两条路径不同，当
且仅当它们经过的岛屿序列不完全相同。
你需要帮助小 P 求出双径岛屿对的数量。
【输入格式】
从文件 migrate.in 中读入数据。
本. 题. 包. 含. 多. 组. 测. 试. 数. 据。.
输入的第一行包含两个非负整数 c, t，分别表示测试点编号与测试数据组数。特别
地，若 c = 0，则该测试点为样例。
接下来依次输入 t 组测试数据。对于每组测试数据：
第一行包含两个正整数 n, d，分别表示岛屿数量和海鸟一次最多能飞行的距离。
第二行包含 n 个严格递增的整数 x1, x2, . . . , xn，依次表示每座岛屿的坐标。
【输出格式】
输出到文件 migrate.out 中。
对于每组测试数据，输出一行一个非负整数，表示双径岛屿对的数量。
0 ≤ c ≤ 25，2 ≤ t ≤ 10^5；
1 ≤ n ≤ 2 × 10^6，N ≤ 2 × 10^6，1 ≤ d ≤ 2 × 10^18；
-10^18 ≤ x1 < x2 < · · · < xn ≤ 10^18
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	long long step;
};
const long long MAX=1e18;
long long a[2000005];
long long dy[2000005];
long long dy1[2000005];
int t;
int c;
long long n,d;
void bfs(long long x,long long step){
	queue<node> q;
	q.push({x,step});
	while(!q.empty()){
		node t=q.front();
		q.pop();
		for(long long i=1;i<=n;i++){
		if(a[i]-t.x<=d&&a[i]-t.x>0){
			q.push({a[i],step+1});
			if(step<=dy1[i]){
				dy1[i]=step;
				dy[i]++;
			}
			
		}
	}
	} 
	
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(long long i=1;i<=n;i++){
			dy1[i]=MAX;
		}
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i]; 
		}
		bfs(a[1],1);
		for(long long i=1;i<=n;i++){
			if(dy[i]==1){
				ans++;
			} 
		}
		cout<<ans;
	} 
	return 0;
}
