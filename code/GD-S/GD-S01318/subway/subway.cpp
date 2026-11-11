#include <bits/stdc++.h>
using namespace std;
int c,n,m,de,que,w[50005],k[505],a[50005][505],t[50005][505];
int d[1001];
vector<int> g[50005];
void bfs(int x,int y)
{
	queue<int> q;
	q.push(x);
	d[x]=1;
	while(q.size()>0)
	{
		int t=q.front();
		if(t==y)
		{
			return;
		}
		q.pop();
		for(int i=0;i<int(g[t].size());i++)
		{
			for(int j=1;j<=k[g[t][i]];j++) 
			{
				if(d[a[g[t][i]][j]]==0)
				{
					d[a[g[t][i]][j]]=d[t]+2;
					q.push(d[a[g[t][i]][j]]);
				}
			}
		}
	}
}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>de>>que;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);//
		}
	}
	while(que--)
	{
		for(int i=1;i<=1000;i++)
		{
			d[i]=0;
		}
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+(d[y])*t[1][1]<<endl;
	}
 	return 0;
} 
//0 3 5 20 5  1 2 3 4 2  2 1 5 2 5 3 3 5 4 5 1 5 3 1 5 5 5 4 5

