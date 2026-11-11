#include<bits/stdc++.h>
using namespace std;
const int M=2e5;
int c,n,m,d,q,w[M],x,y,ans,t[52][1500];
bool vis[505];
vector<int> xian[505];
void dfs(int ed,int u,int xi,int cun)
{
	if(u==ed)
	{
		ans=min(ans,cun+w[u]+t[xi][u]);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i][u]==0)
		{
			continue;
		}
		for(int j=0;j<xian[i].size();j++)
		{
			int to=xian[i][j];
			if(vis[to])
			{
				continue;
			}
			vis[to]=true;
			if(xi!=i)
			{
				dfs(ed,to,i,cun+t[xi][u]+t[i][u]);
			}
			else
			{
				dfs(ed,to,xi,cun);
			}
			vis[to]=false;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int to;
			cin>>to;
			xian[i].push_back(to);
			cin>>t[i][to];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		ans=2147483647;
		dfs(y,x,0,w[x]);
		cout<<ans<<endl;
	}
	return 0;
 }
