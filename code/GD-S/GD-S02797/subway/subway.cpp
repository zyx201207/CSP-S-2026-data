#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXM=5e4+10;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
int k[MAXN],t[MAXN][MAXM],a[MAXN][MAXM];
int atline[MAXM];
vector<pair<int,int>> vec[MAXN];
int w[MAXM];
int ans=inf;
bool vis[MAXN];
int xr,yr;
int dfs(int line,int val)
{
	int recieve=inf;
	for(int i=1;i<=k[line];i++)
	{
		int stop=a[line][i];
		if(stop==yr)
		{
			int min_timing=inf;
//			for(auto e:vec[yr])
//				min_timing=min(min_timing,e.second);
//			if(q==0)
//				cout<<w[yr]<<endl;
//				cout<<min_timing;
//			cout<<val+min_timing+w[yr]<<endl;
			return val+t[line][i]+w[yr];
		}	
		for(auto e:vec[stop])
		{
			int v=e.first,w=e.second;
			if(vis[v])continue;
			vis[v]=1;
			recieve=min(recieve,dfs(v,val+t[line][i])+w);
//			ans=min(ans,dfs(v,val+t[line][i])+w);
			vis[v]=0;
		}
	}
	return recieve;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			vec[a[i][j]].push_back({i,t[i][j]});
		}
	}
//	cout<<vec[2][0].second<<" "<<vec[2][1].second;
	while(q--)
	{
		cin>>xr>>yr;
		memset(vis,0,sizeof(vis));
		int res=inf;
//		cout<<t[1][1]<<endl;
		for(auto e:vec[xr])
		{
			int v=e.first;
			vis[v]=1;
//			cout<<w[xr]+t[v][xr]<<endl;
			res=min(res,dfs(v,w[xr]+e.second));
			vis[v]=0;
		}
		cout<<res<<endl;
	}
	return 0;
}
