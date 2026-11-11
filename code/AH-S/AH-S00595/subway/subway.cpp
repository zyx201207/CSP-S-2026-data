#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,w[500010],i,x,y,qz[500010],ans;
int t[510][500010];
short int a[510][500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	i=0;
	for(i=1;i<=n;i++)
	{
		long long int k,a1,j1;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			scanf("%lld %lld",&a1,&j1);
			a[i][a1]=1;
			a[0][a1]++;
			t[i][a1]=j1;
			t[0][a1]+=j1;
		}
	}
	int minx=2e9;
	if(n==2)
	{
		for(i=1;i<=m;i++)
		{
			if(a[0][i]==2)
			{
				minx=min(t[0][i],minx);
			}
		}
	}
	while(q--)
	{
		scanf("%lld %lld",&x,&y);
		if(n==1)
		{
			ans=w[x]+w[y]+t[1][x]+t[1][y];
			printf("%lld\n",ans);
			continue;
		}
		if(n==2)
		{
			ans=w[x]+w[y]+min(((a[1][x]&&a[1][y])?(t[1][x]+t[1][y]):(t[0][x]+t[0][y]+minx)),((a[2][x]&&a[2][y])?(t[2][x]+t[2][y]):(t[0][x]+t[0][y]+minx)));
			printf("%lld\n",ans);
			continue;
		}
		if(d==1)
		{
			ans=w[x]+w[y]+t[0][x]+t[0][y];
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}
