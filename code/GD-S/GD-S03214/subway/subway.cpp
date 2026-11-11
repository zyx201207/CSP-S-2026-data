#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> g[22];
struct line
{
	int k,sta[500005],t[500005];
}a[505];
struct stop
{
	int name,w;
}sto[500005];
int bfs(int s,int e)
{
	queue<int> q;
	vector<int> dist(m+1,-1);
	dist[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:g[u])
		{
			if(dist[v]==-1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[s];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> sto[i].w;
		sto[i].name=i;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i].k;
		for(int j = 1 ; j <= a[i].k ; i++)
		{
			int na,t1;
			cin >> na >> t1;
			a[i].sta[j]=na,a[i].t[j]=t1;
			if(j>=2)
			{
				g[a[i].sta[j-1]].push(na);
				g[na].push(a[i].sta[j-1]);
			}
		}
	}
	for(int i = 1 ; i <= q ; i++)
	{
		int x,y;
		cin >> x >> y;
		int ans=bfs(x,y);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
