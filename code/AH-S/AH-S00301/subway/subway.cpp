#include<bits/stdc++.h>
using namespace std;
int w[500010],h[1010],id[1010][1010],t[1010][1010];
int c,n,m,d,q,ans,u,v;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		for(int j=1;j<=h[i];j++)
		{
			cin>>id[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		cin>>u>>v;
		ans=w[u]+w[v];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=h[i];j++)
			{
				if((id[i][j]-u)%(c*1.5)==0||id[i][j]==v)
				{
					ans+=t[i][j];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

