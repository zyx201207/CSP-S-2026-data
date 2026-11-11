#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5*1e5+100;
ll sta_time[M];//各地铁站从地铁口走到站厅需要的时间 
ll a[M],t[M];
int C,n,m,d,q;
//测试点编号C、地铁线路数n、地铁站数m
//每个地铁站最多被d条线路经过，出行计划数q 
int k,b,e;
struct Map{
	int u,v;
	ll w;
}maps[10000100];
ll cnt=0;ll dp[M][M],dp1[M][M];
int fa[M];
bool cmp(Map i,Map j){
	return i.w<j.w;
}
int find(int x){
	if (x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void init(int num){
	for (int i=1;i<=num;i++) fa[i]=i,dp[i][i]=0;
}
struct node{
	int v;
	ll value;
};

vector<node> vec[M];
bool dps[M];
queue<node> Q;
int main()
{
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x7f,sizeof(dp));
	cin>>C>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
		cin>>sta_time[i];
	init(m);
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		for (int j=1;j<=k;j++)
			cin>>a[i]>>t[i];
		for (int j=1;j<k;j++)
		maps[++cnt].u=a[i];
		maps[cnt].v=a[i+1];
		maps[cnt].w=t[i]+t[i+1];	
	}
	sort(maps+1,maps+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)
	{
		int f_u=find(maps[i].u),f_v=find(maps[i].v);
		if (f_u!=f_v)
		{
			fa[f_u]=f_v;
			dp[maps[i].u][maps[i].v]=dp[maps[i].v][maps[i].u]=maps[i].w;
		}
	}
	for (int i=1;i<=q;i++)
	{
		memset(dp1,0x7f,sizeof(0));
		memset(dps,0,sizeof(0));
		cin>>b>>e;
		for (int k=1;k<=m;k++)
			for (int i=1;j<=m;i++)
				for (int j=1;j<=m;j++)
					dp1[i][j]=min(dp[i][k]+dp[k][j])
		cout<<dp[b][e]+sta_time[b]+sta_time[e]<<endl;
	}
	return 0;
}


