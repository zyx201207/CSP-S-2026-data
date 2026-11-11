#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long c,d,q,n,m,cnt;
long long a[N];
long long k[N];
struct subway
{
	long long id;
	long long t;
	
}b[N];
vector<subway>mp[N];
bool cmp(subway x,subway y)
{
	return x.id>y.id;
}
long long dis[3000][3000];
void Dij(int x)
{
	
	dis[x][x]=0;
	queue<int>g;
	g.push(x);
	while(!g.empty())
	{
		int u=g.front();g.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i].id;
			int w=mp[u][i].t;
			if(dis[x][v]>dis[x][u]+w)
			{
				dis[x][v]=dis[x][u]+w;
				g.push(v);
			}
		}
	}
}
void query(int x,int y)
{
	
	
		cout<<dis[x][y]+a[x]+a[y]<<'\n';
	
	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>b[cnt].id>>b[cnt].t;
			
			cnt++;
		}
		int x=cnt-k[i];
		//cout<<b[3].id<<endl;
		for(int j=x;j<cnt;j++)
		{
			for(int u=j+1;u<cnt;u++)
			{
				mp[b[j].id].push_back({b[u].id,b[j].t+b[u].t});
				mp[b[u].id].push_back({b[j].id,b[j].t+b[u].t});
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=cnt;i++)
	{
		Dij(i);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;cin>>x>>y;
		query(x,y);
		
	}
	return 0;
	
}
