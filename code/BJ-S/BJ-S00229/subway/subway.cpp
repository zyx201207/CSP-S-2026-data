#include<bits/stdc++.h>
using namespace std;
int dis[200005];
int vis[200005];
int w0[200005];
vector<int>g[200005];
vector<int>w[200005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>w0[i];
		}
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			int a1,t1,a2,t2;
			cin>>a1>>t1>>a2>>t2;
			g[a1].push_back(a2);
			g[a2].push_back(a1);
			w[a1].push_back(t1+t2);
			w[a2].push_back(t2+t1);
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			queue<int>q;
			for(int i=1;i<=m;i++)
			{
				dis[i]=1e9;
				vis[i]=0;
			}
			dis[x]=0;
			q.push(x);
			while(!q.empty())
			{
				int f=q.front();
				q.pop();
				vis[f]=0;
				for(int i=0;i<g[f].size();i++)
				{
					int y=g[f][i];
					if(dis[y]>dis[f]+w[f][i])
					{
						dis[y]=dis[f]+w[f][i];
						if(!vis[y])
						{
							vis[y]=1;
							q.push(y);
						}
					}
				}
			}
			cout<<w0[x]+w0[y]+dis[y]<<endl;
			// return 0;
		}
		return 0;

	}
	int diancnt=m;
	for(int i=1;i<=m;i++)
	{
		cin>>w0[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int add,ti;
			diancnt++;
			if(j>=2)//线路之间互相联通
			{
				g[diancnt].push_back(diancnt-1);
				g[diancnt-1].push_back(diancnt);
				w[diancnt].push_back(0);
				w[diancnt-1].push_back(0);
			}
			cin>>add>>ti;
			g[diancnt].push_back(add);
			g[add].push_back(diancnt);
			w[diancnt].push_back(ti);
			w[add].push_back(ti);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		queue<int>q;
		for(int i=1;i<=m+diancnt+10;i++)
		{
			dis[i]=1e9;
			vis[i]=0;
		}
		dis[x]=0;
		q.push(x);
		while(!q.empty())
		{
			int f=q.front();
			q.pop();
			vis[f]=0;
			for(int i=0;i<g[f].size();i++)
			{
				int y=g[f][i];
				if(dis[y]>dis[f]+w[f][i])
				{
					dis[y]=dis[f]+w[f][i];
					if(!vis[y])
					{
						vis[y]=1;
						q.push(y);
					}
				}
			}
		}
		cout<<dis[y]+w0[x]+w0[y]<<endl;
	}
	return 0;
}