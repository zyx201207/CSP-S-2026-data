#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt,dis[305][305],c,t,n,d,x[2000010],an[305][305];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ll ans=0;
		memset(an,0,sizeof(an));
		memset(dis,0x3f3f,sizeof(dis));
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((ll)abs(x[j]-x[i])<=d)
				{
					dis[j][i]=1;
//					cout<<i<<" "<<j<<"\n"; 
				}
				if((ll)abs(x[i]-x[j])<=d)
				{
					dis[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dis[i][k]+dis[k][j]<dis[i][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
						an[i][j]=max(1ll,an[i][k]+an[k][j]);
					}
					else if(dis[i][k]+dis[k][j]==dis[i][j]) an[i][j]++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				cout<<i<<" "<<j<<dis[i][j]<<" "<<an[i][j]<<"\n";
				if(an[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
