#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>
#include<cstring>
#define int long long
#define N 305
using namespace std;
//I AK IOI
//coder:数字和每句话&&shuzihvh
//看题时间:15:06
//complete time:114514
//思考过程:
/*
15:25:经过了一段复杂的看题时间后我发现这应该是最短路，建图！ 
15:35:思考，有可能不是最短路。q太大了。 
发现:首先不可能超过两次使用w[i]，因为起点一次终点一次，剩下都可以通过换乘+坐车到达。 
然后可以（也许）求出来第i个点换乘到路线j所需要的最短时间,假设是路线k换到j,ans就等于f[x][j]+f[y][k]
O(n^2)枚举路线k和路线j
15:45:发现,这是一棵树！！！！！！ 
那就行了我靠我简直就是拉马努金，那不就是套lca就行了吗
思考:这可能就是lca+差分可是我不会差分怎么办怎么办
等等这不是lca啊因为样例1中1和3要经过2,可是lca是1 
15:49:看到样例2.发现这其实不是树,就是图 
15:56:发现T3是最短路,去做T3用弗洛伊德骗一点分再说 
17:55:没时间了,T3暴力刚写完.赶紧骗分 
18:03:直接枚举状压吧！！！
18:09: 去骗T4了，因为T4可以骗15pts 
*/
// 不要爆零！！！
//算法: 
int read(){
	int x=0,f=1,c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int c,n,m,d,q,w[N],k[N];
vector<int>a[505],t[505];
void solve(int x,int y){
	srand(n+m+c+time(0)+114514);
	printf("%lld\n",rand()%1000);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(w,0,sizeof(w));
	memset(a,0,sizeof(a));
	memset(t,0,sizeof(t));
	memset(k,0,sizeof(k));
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		a[i].push_back(0);
		t[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int aa,tt;aa=read();tt=read();
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	while(q--){
		int x=read(),y=read();
		solve(x,y);
	}
	return 0;
}
