#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int M=505;
const int inf=1e18;
int c,n,m,d,q;
int o[N];
vector<pair<int,int>>p[N];
//根据d,p[i].size()<=20 
int e[M][M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)e[i][j]=inf;
	for(int i=1;i<=m;i++)
		cin>>o[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int x,w;k;k--)
		{
			cin>>x>>w;
			p[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
		for(auto [x,wx]:p[i])
			for(auto [y,wy]:p[i])
				if(x!=y)
					e[x][y]=min(e[x][y],wx+wy),
					e[y][x]=min(e[y][x],wx+wy);
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	for(int l,r;q;q--)
	{
		cin>>l>>r;
		int ans=inf;
		for(auto [x,wx]:p[l])
			for(auto [y,wy]:p[r])
				ans=min(ans,e[x][y]+wx+wy);
		cout<<ans+o[l]+o[r]<<'\n';
	}
	return 0;
}
/*
捋一下题意，太绕了

一共有n条线路，每条线路经过若干个站
到站了，上下车需要走路

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

这个样例1

相当于有2条线路，5个站，每个站最多会有20个线路，2个询问
[4,1,9,2,5]是记得最后加上
第一条线路经过3个站，分别是[1,2,4]，从线路上下车需要的代价分别是[5,7,6]
第二条线路经过3个站，分别是[2,3,5]，从线路上下车需要的代价分别是[3,4,7]

查询一下 1->3
5+7+3+4+(4+9)=32 
查询一下 1->2
5+7+(4+1)=17

那大概就是这样本质最短路了

走第i条线，从x站到y站，代价是w[i][x]+w[i][y]

直接这样连边显然不对，就是只有一条路也是m^2级别的

注意到n很小，d也很小，这启发了什么？

线路和线路连边吗？

第一条线路可以和第二条线路连边，通过站点2，边权应该是10

好了。

以站点作转移即可。 
*/
