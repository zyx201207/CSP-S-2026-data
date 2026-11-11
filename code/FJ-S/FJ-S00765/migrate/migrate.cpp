#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
#define N 21
using namespace std;
//I AK IOI
//coder:数字和每句话&&shuzihvh
//看题时间:15:56
//complete time:17:53
//思考过程:
/*
ok也是打算用floyd骗分。
O(n^2)求出能达到的岛建图 O(n^3)求最短路 O(n^2)求双双 
//16:07 发现这并不能用最短路算法
我想到了，枚举起点和终点然后再计数
性质:x[i]若与x[i+k]的距离大于d，那么x[i]与x[i+k+...]的距离也一定大于d 并且是最短路所以只能从左到右 
可以试试求出最后一个小于等于d的地方,没有就返回n(也就是这i到n所有都小于d)
16:30 求好了 
换言之,mm[i]指的是,最多能从i到mm[i]这个点
那应该可以dp吧
16:37 思考,可以枚举断点k.如果mm[i]大于等于k且mm[k]大于等于j说明可以从i到k,从k到j
那么此时f[i][j]=f[i][k]+f[k][j]
如果x[i]大于等于k且x[k]小于j那就说明 
16:57 不对这最短路不是路程而是降落的次数，气死我了 
16:59 只剩1.5h，打暴力吧，做什么dp啊气死我了 
17:05 还能蒸再蒸一会儿 dp[i][j]为i到j的最短路条数 
17:12 蒸个头还是打暴力吧 
17:20 设mindis[i][j]为i到j的最短路经过多少次点 
17:53 终于打完暴力了。。O(2*2^n*n) 
*/
// 不要爆零！！！
//算法: 状压骗分 
int read(){
	int x=0,f=1,c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,d,x[N],mm[N],mindis[N][N],dis[N][N],vis[(1<<N)],ans;
void solve(){
	n=read();d=read();ans=0;
	memset(mm,0,sizeof(mm));
	memset(x,0,sizeof(x));
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(mindis,0x3f,sizeof(mindis));
	for(int i=1;i<=n;i++)x[i]=read();
	x[n+1]=2e18+5;
	int i=1,j=1;
	while(i<=n&&j<=n){
		if(x[j]-x[i]>d){
			mm[i]=j-1;
			i++;
		}
		else if(x[n]-x[i]<=d){
			mm[i]=n;
			i++;
		}
		else j++;
	}
	for(int mask=0;mask<(1<<n);mask++){
		int cnt=0,p[N]={0},flag=0;
		for(int i=1;i<=n;i++)if(mask&(1<<(i-1)))p[++cnt]=i;
		for(int i=1;i<cnt;i++){
			if(mm[p[i]]<p[i+1]){
				flag=1;
			}
		}
		if(!flag){
			mindis[p[1]][p[cnt]]=min(mindis[p[1]][p[cnt]],cnt);
		}
	}
	for(int mask=0;mask<(1<<n);mask++){
		int cnt=0,p[N]={0},flag=0;
		for(int i=1;i<=n;i++)if(mask&(1<<(i-1)))p[++cnt]=i;
		for(int i=1;i<cnt;i++){
			if(mm[p[i]]<p[i+1]){
				flag=1;
			}
		}
		if(!flag){
			if(!vis[mask]&&cnt==mindis[p[1]][p[cnt]])dis[p[1]][p[cnt]]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j>i&&i<n&&dis[i][j]==2)ans++;
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--)solve();
	return 0;
}
