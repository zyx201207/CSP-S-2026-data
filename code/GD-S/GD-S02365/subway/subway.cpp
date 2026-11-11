#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int>dian[500005];
vector<int>xian[505];
int vis[500005];
int t[505][500005]={0};//站厅到站台 
int ans;
void dfs(int s,int e,int tmp)
{
	if(s==e)
	{
		ans=min(ans,tmp);
		return;
	}
	if(vis[s])
	{
		return;
	}
	vis[s]=1;
	for(int i=0;i<xian[s].size();i++)
	{
		int now=xian[s][i];//可以去哪些线
		for(int j=0;j<dian[now].size();j++)
		{
			int zhuan=dian[now][j];//线上有哪些点 
			dfs(zhuan,e,tmp+t[now][s]+t[now][zhuan]);
		} 
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//c有啥用? 
	cin>>c>>n>>m>>d>>q;//n条线,m个站 
	int w[m+5]={0};//地铁口到站厅 
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];	
	}
	for(int i=1;i<=n;i++)//i号线经过哪k个点 
	{
		int k;//有几站 
		cin>>k;
		for(int j=1;j<=k;j++)//哪个点,站厅到站台时间 
		{
			int a;
			cin>>a>>t[i][j];
			xian[a].push_back(i);//a点有哪些线路
			dian[i].push_back(a);//i线有a点 
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		ans=0x3f3f3f3f;
		int xy=w[x]+w[y];
		dfs(x,y,0);
		cout<<ans+xy<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

