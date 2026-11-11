#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int t;//地铁口到站厅的时间 
	int s[105];//站厅到本站台第i线路的时间 
}a[5000005];
int n,m,d,q;
int u,v;
vector<int> p[5000005];
int dfs(int begin)
{
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	if(c==0)
	{
		c=1;
	}
	while(c)
	{
		int n,m,d,q;
		cin>>m>>n>>d>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].t;
		}
		for(int i=1;i<=m;i++)
		{
			int k,t;
			int sn;
			cin>>sn;
			for(int j=1;j<=sn;j++)
			{
				cin>>k>>t;
				p[i].push_back(k);
				a[k].s[i]=t;
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>u>>v;
			long long time=0;
			time+=a[u].t+a[v].t;
			time+=dfs(u);
			cout<<time;
		} 
		cin>>c;
	}
	return 0;
}
