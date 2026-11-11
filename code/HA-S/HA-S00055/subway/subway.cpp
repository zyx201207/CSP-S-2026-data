#include<bits/stdc++.h>
using namespace std;
#define ll long long
//牛逼看到这个雷霆题面已经想死了
//先读懂题吧（
int c,n,m,d,Q; 
//注意到d很小，这一定是个突破点
//怎么这么像道路修复。。 
//首先这个w是没用的，因为这部分的贡献是一定的，所以下面那m个点都是没用的
const int N=505,M=5e5+5; 
const long long INF=0x3f3f3f3f3f3f3f3f; 
//然后现在图变成了一个n层链的图，且链上的边边权为0
//哎所以我们其实可以枚举起点走向哪条链对吗
//这个应该是有前途的因为d很小 
//又因为链上走没有代价，所以我们考虑预处理出从i链换到j链的代价
//处理出这个然后查询O(d^2)查询，有点紧张但应该可过
//好的现在考虑如何处理
//定义dp_i_j表示i链换到j链的代价，可以类比floyd写一个n^3的dp对吗
//试试？
//别急这个咋预处理来着。。。 
//哦哦可以O(m*d^2)预处理，不是哥们这个大小真的可以吗，为啥这题只给1s时限
//可以个蛋，2e8咋可能可以
//就是说我这样写能拿76pts，但我觉得还能蒸
//别急我为啥不\sum k_i *d预处理 
//答案是对了就是跑的太慢了啊。。。 
//应该没办法优化了，考虑卡卡常吧 
//停停停O(n^3)真的对吗？。
//woc瓶颈在floyd啊
//这个我咋优化。。。 
//别急，先把特殊性质打了 
int w[M];
ll dp[N][N];
int k[N];
struct node{
	int a,t;
};
vector<node>vt[N],to[M];
/*solve_task_A
每条路最多连两个点，所以每个链最多连着40个其他链 
然后跑dijkstra就成功得到了一个复杂度类似于floyd的算法。。。
哎我怎么连特殊性质都不会啊 
*/

/*solve_task_B
可以转化为每个点到链的距离都为1
所以链到其他链的距离为2，从每条链开始跑bfs即可 
为啥跑的更慢了。。。 
不对啊，我不加bfs都有点超时了
哎bfs复杂度是不是O(n+m)来着
完蛋了我是【】 
*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;	
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			vt[i].push_back({a,t});
			to[a].push_back({i,t});	
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++){
		for(node pir:vt[i]){
			int a=pir.a,t=pir.t;
			for(node tmp:to[a]){
				dp[i][tmp.a]=dp[tmp.a][i]=min(dp[i][tmp.a],(ll)t+tmp.t); 
			}
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
	while(Q--){
		int x,y;
		cin>>x>>y;
		ll ans=INF;
		for(node tmp1:to[x]){
			int a1=tmp1.a,t1=tmp1.t;
			for(node tmp2:to[y]){
				int a2=tmp2.a,t2=tmp2.t;
				ans=min(ans,dp[a1][a2]+t1+t2);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

