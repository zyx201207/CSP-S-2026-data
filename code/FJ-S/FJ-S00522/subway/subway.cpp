#include<bits/stdc++.h>
using namespace std;
int w[500005],a[500005],t[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
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
			cin>>a[i][k]>>t[i][k];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int r=0;
		r+=(w[x]+w[y]);
		for(int i=1;i<=n;i++)
		{
			for(int i=1;i<=k;i++)
			{
				if(x==t[n][k])
				{
					r+=t[n][k];
				}
			}
		}
		cout<<r<<'\n';
	}
	
	return 0;
}
