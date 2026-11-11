#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[3005];
long long k[3005];
long long a[3005][3005];
long long t[3005][3005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>1000)
		{
			for(long long j=1;j<=q;j++) cout<<1<<endl;
			return 0;
		}
		for(long long j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long l=1;l<=q;l++)
	{
		long long x,y,ans,minn=1e15;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(long long i=1;i<=n;i++)
		{
			long long flag=0,c=0;
			for(long long j=1;j<=k[i];j++)
			{
				if(a[i][j]==x) 
				{
					c+=t[i][j];
					flag++;
				}
				if(a[i][j]==y)
				{
					c+=t[i][j];
					flag++;
				}
			}
			if(flag==2) minn=min(minn,c);
		}
		if(minn!=1e15) ans+=minn;
		cout<<ans<<endl;
	}
	return 0;
}
