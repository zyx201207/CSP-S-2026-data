#include<bits/stdc++.h>
using namespace std;
long long q,c,n,m;
long long mp[2000006];
int tas(int l,int r,int step)
{
	if(l==r&&step==0)
	{
		return 1;
	}
	else if(l==r&&step!=0)
	{
		return 0;
	}
	else if(step==0)
	{
		return 0;
	}
	int ans=0;
	for(int i=l+1;i<=r;i++)
	{
		ans+=tas(i,r,step-1);
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&q,&c);
	for(int o=1;o<=c;o++)
	{
		memset(mp,0,sizeof(mp));
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&mp[i]);
		}
		int cz=mp[2]-mp[1];
		int fl;
		fl=m/cz;
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=tas(i,j,fl);
			}
		}
		cout<<ans;
	}
	return 0;
}
