#include<bits/stdc++.h>
using namespace std;
int inf=2147483646;
struct str{
	int v,w;
};
queue<int>q;
int dis[1005],s;
vector<str>ve[1005];
int c,n,m,d,aa,w[1005],k[1005],ans;
void fd(int s)
{
	q.push(s);
	for(int i=1;i<=m;i++)dis[i]=inf;
	dis[s]=0;
	while(!q.empty())
	{
		int xx=q.front();
		q.pop();
		for(auto y:ve[xx])
		{
			if(dis[y.v]>dis[xx]+y.w)
			{
				dis[y.v]=dis[xx]+y.w;
				q.push(y.v);
			}
		}
	}
}
signed main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>aa;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2)
		{
			return 0;
		}
		int u1,u2,t1,t2;
		cin>>u1>>t1>>u2>>t2;
		ve[u1].push_back({u2,t1+t2});
		ve[u2].push_back({u1,t1+t2});
	}
	while(aa--)
	{
		int y;
		cin>>s>>y;
		ans=w[s]+w[y];
		fd(s);
		cout<<ans+dis[y];
	}
	return 0;
}
