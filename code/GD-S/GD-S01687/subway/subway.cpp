#include <bits/stdc++.h>
#define ll long long
using namespace std;
// 0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
ll c,n,m,dd,q,k[505],vis[500005],minn=500000005;
struct st{
	ll w,t[505]; 
}stop[500005];
vector<int> g[500005];
void f(int u,int v,int s)
{
	if(u==v)
	{
		minn=min(s,minn);
		return;
	}
	else
	{
		for(int i=0;i<g[u].size();i++)
		{
			if(vis[i]==0)
			{
				vis[i]=1;
				
			}
		}
	}
}
int main()
{
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>stop[i].w;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			ll x,y;
			cin>>x>>y;
			stop[x].t[i]=y;
			g[x].push_back(y);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[x]=1;
		cout<<f(x,y)<<endl;
		vis[x]=0;
	}

	
	
	
	
	fin.close();
	fout.close();
}
