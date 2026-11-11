#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N1=5e2+5,N2=5e5+5;
//每次站内换乘都需要从一条线路的站台先走到站厅，再从站厅走到另一条线路的站台 !!!?
//将每个线路打包成一个连通块，块内间节点移动不需要时间（地铁上步行？ 
//d的用处就是告诉你一个点最多存在于d个连通块里（？
//FLOYD（n<=500，多次提问要求全源最短路
//Simulation 
struct node{
	int id;
	long long dis;
};

long long dp[N1][N1];//Floyd答案 
long long w[N2];
int k[N1];//连通块大小 
vector<int> G[N1];//一条线有哪几个点 
vector<node> MP[N2];//此外，要记录下每个点被哪些线经过，以及从站厅到这个站点要多少时间？
void solve(){
	int c,n,m,d,q;
	scanf("%d",&c);//考虑到输入较大//?????? 
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&d);
	scanf("%d",&q); 
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j]=dp[j][i]=1e18;
		scanf("%d",&k[i]);
		int x;
		long long y;
		for(int j=1;j<=k[i];j++){
			scanf("%d",&x);
			scanf("%lld",&y);
			G[i].push_back(x);//i线路里有x站点 
			MP[x].push_back((node){i,y});
			
		}
		
	}
	//遍历每一个点，遍历与之相连的所有连通块，通过该点为媒介将其两两建边。floyd不能有重边所以要min
	
	for(int i=1;i<=m;i++){//5e5
		for(auto u:MP[i]){//20
			for(auto v:MP[i]){//20
				if(u.id==v.id) continue;
				dp[u.id][v.id]=dp[v.id][u.id]=min(dp[u.id][v.id],u.dis+v.dis);
			}
		}
	} 
	//跑Floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	} 
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		//自己里边转一圈的花费为0.尽管这应该在输出时特判，但我懒得写了 
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e17;
		//一个点最开始有多个可选择连通块作为起点，结束时也有多个可选择连通块作为终点 
		for(auto u:MP[x]){
			for(auto v:MP[y]){
				ans=min(ans,u.dis+v.dis+dp[u.id][v.id]);
			}
		} 
//		cout<<ans<<endl;
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	
	//16:52 
	//不知道为什么在这里运行这么慢，无输入跑了3.2s，怀疑机子有问题 
	//总不能是我的问题吧？ 
	//不能...吧？ 
	//18:12
	//第4题也出现了这个问题，但我通过把cin改scanf的方式救回来了
	//排除法发现这里也是输入出了问题，可我输入一开始就是scanf啊......
	//怎么办怎么办 
	//why？ 
	return ;
}


int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int t=1;
	while(t--){
		solve();
	}
	
	return 0;
}
