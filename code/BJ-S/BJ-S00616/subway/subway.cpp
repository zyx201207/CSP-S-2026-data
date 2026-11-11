#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ztk[511000],k,x,y;
struct zx
{
	int z[50000],t[50000],w;
}a[1100];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>ztk[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		a[i].w=k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i].z[j]>>a[i].t[j];
		}
	}
	while(q--)
	{
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].w;j++)
			{
				if(a[i].z[j]==x)
				{
					ans+=ztk[x];
				}
			}
		}
		ans+=ztk[y];
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].t[i];
			ans+=a[i].t[i+1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
