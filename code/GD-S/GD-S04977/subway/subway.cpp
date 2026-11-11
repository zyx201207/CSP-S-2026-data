#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500100];

struct node
{
	int to;
	long long time;
	//station[i][j]表示从第 i个站厅到第 to号线站台的用时
};

vector<node> station[500100];

long long ma[510][510];//ma[i][j]表示从i号线到j号线的最短路线，只考虑同站换乘 ;

void geti()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		long long time;
		for(int j=1,a;j<=k;j++)
		{
			cin>>a>>time;
			station[a].push_back({i,time});
		}
	}
}

void prefloyd()
{
	memset(ma,0x3f,sizeof(ma));
	
	for(int i=1;i<=n;i++)
		ma[i][i] = 0;

	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<station[k].size();i++)
		{
			for(int j=i+1;j<station[k].size();j++)
			{
				node t1 = station[k][i];
				node t2 = station[k][j];
				ma[t1.to][t2.to] = ma[t2.to][t1.to] = min(ma[t1.to][t2.to],t1.time + t2.time);
			}
		}
	}
}

void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				ma[i][j] = min(ma[i][j],ma[i][k] + ma[k][j]);
		}
	}
}


void tprint()
{
	long long x,y,ans;
	while(q--)
	{
		cin>>x>>y;
		ans = 1e18;
		for(int i=0;i<station[x].size();i++)
		{
			for(int j=0;j<station[y].size();j++)
			{
				node t1 = station[x][i];
				node t2 = station[y][j];
				ans = min(ans,ma[t1.to][t2.to] + t1.time + t2.time);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	geti();
	
	prefloyd();
	
	floyd();
	
	tprint();
	
	return 0;
} 
