#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010]; 
int t[500010];
int a[500010];
int tag;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k*2;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	for(int i=1;i<=k*2;i++)
	{
		cin>>t[i];
	}
	while(q--)
	{
		int x;
		int y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		for(int i=x;i<=y;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]==x+1)
				{
					ans+=t[i];
				}
				else
				{
					break;
				}
			}
			ans+=t[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
