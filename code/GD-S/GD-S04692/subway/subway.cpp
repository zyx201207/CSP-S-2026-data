#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10005],k[1005],a[1005][1005],t[1005][1005],ans=0,ton[500005];
bool sa=1,sas=1;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin>>a[i][j]>>t[i][j];
			ton[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;++i)
	{
		int x,y;
		cin>>x>>y;
		ans=0;
		for(int z=1;z<=n;++z)
		{
			for(int j=1;j<=k[z];++j)
			{
				if(a[z][j]==x&&sa)
				{
					ans+=t[z][j];
					sa=0;
				}
				if(a[z][j]==y&&sas)
				{
					ans+=t[z][j];
					sas=0;
				}
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
