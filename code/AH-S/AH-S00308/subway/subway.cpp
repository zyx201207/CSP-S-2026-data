#include<bits/stdc++.h>
using namespace std;
int n,m,d,p,C,i,j,s,s1,w[505005],t[505005],dis[505005],f[505005];
vector<pair<int,int>> a[1005005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dij(int u,int v)
{
	memset(dis,0,sizeof(dis));
	memset(f,0,sizeof(f));
	while(!q.empty()) q.pop();
	q.push({0,u});
	while(!q.empty())
	{
		int q2=q.top().first,q1=q.top().second;
		f[q1]=1;
		q.pop();
		for(auto o:a[q1])
		{
			int v1=o.first,w1=o.second;
			if(!f[v1])
			{
				f[v1]=1;
				dis[v1]=q2+w1;
				if(v1==v)
				{
					return ;
				}
				q.push({dis[v1],v1});
			}
		}
	}
	//cout<<dis[v]<<'\n';
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>d>>p;
	for(i=1;i<=m;i++)
	{
		cin>>w[i];
		t[i]=m+i;
		a[i].push_back({t[i],w[i]});
		a[t[i]].push_back({i,w[i]});
	}
	for(i=1;i<=n;i++)
	{
		int sh;
		cin>>sh;
		for(j=1;j<=sh;j++)
		{
			int u,v;
			cin>>u>>v;
			//cout<<t[u]<<' ';
			a[2*m+i].push_back({t[u],v});
			a[t[u]].push_back({(2*m+i),v});
		}
		//cout<<'\n';
	}
	s=2*m+n;
	while(p--)
	{
		int u1,v1;
		cin>>u1>>v1;
		dij(u1,v1);
		//for(i=1;i<=s;i++) cout<<dis[i]<<' ';
		cout<<dis[v1];
		cout<<'\n';
	}
	return 0;
}
