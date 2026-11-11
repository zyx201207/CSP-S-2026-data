#include<bits/stdc++.h>
using namespace std;
const long long Ma=0x3f3f3f3f3f3f3f3f;

struct zd{
	long long id,xl,xls;
};

struct dl{
	long long xl,ss;
}; 

long long C,n,m,d,q;
long long w[514514],k[514514];
long long a[505][2005],t[505][2005];
long long x[114514],y[114514];
vector<zd> ve[514514];
//每个站点可到达的其他站点(编号id,线路xl,线路的第xls个站)

vector<dl> xlss[514514];//第i个站点是.xl线路的第.s个站 

long long ans=Ma;
long long dfs(int st,int ed,int fy)//费用 
{
	if(st==ed) return fy;
	for(auto v:ve[st])//可到达的其他站点 
	{
		return dfs(v.id,ed,fy+t[v.xl][v.xls]+t[v.xl][xlss[v.id][v.xl].ss]);
		//fy+厅到该线路的台+台到v站的厅 
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			xlss[a[i][j]].push_back({i,j});
		}
		for(int j=1;j<=k[i];j++)
			for(int c=1;c<=k[i];c++)
				ve[a[i][j]].push_back({a[i][c],i,c});
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		printf("%lld\n",dfs(x[i],y[i],w[x[i]]+w[y[i]]));//初始自带起点和终点的 口-厅 
	}
	
	
	return 0;
}
/*酣畅淋漓的大模拟
m个站(1-m)，w[v]为车站v的 口-厅 往来耗时
n条路(1-n)，第i条经过k[i]个地铁站，a[i][k[i]]为在第i条路的第k[i]个地铁站编号
t[i][j]为在第a[i][j]个地铁站的 厅-i线站台 往来耗时
每个地铁站最多有d个线台
每个站都是互相连通的
q个出行计划，从x[r]->y[r]
求每个出行计划的最小步行耗时 
 
从x[r]出发
若有线路可直达y[r]，直接走
若不行，则随便走一个点，为新的出发点，重复上述步骤
DFS?


*/
//endl -> \n
//long long
//max
