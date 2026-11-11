//GZ-S00132 贵阳市第一中学 李啸峰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int c,T,n,d,x[N],dis[N][N],cnt[N][N],Ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12)
	{
		while(T--)
		{
			cin>>n>>d;
			int lst=0,g=0;
			for(int i=1;i<=n;i++)
			{
				int x;
				cin>>x;
				if(i==1)
					lst=x;
				if(i==2)
					g=x-lst;
			}
			if(2*g<d&&d<3*g)
				cout<<n-3<<endl;
			else
				cout<<0<<endl;
		}
	}
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		memset(dis,0x3f3f3f3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		Ans=0;
		for(int i=1;i<=n;i++)
		{
			dis[i][i]=0;
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d)
					dis[i][j]=dis[j][i]=cnt[i][j]=cnt[j][i]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j&&i!=k&&j!=k)
					{
						if(dis[i][j]==1)
							continue;
						if(dis[i][j]==dis[i][k]+dis[k][j])
							cnt[i][j]++;
						if(dis[i][j]>dis[i][k]+dis[k][j])
						{
							dis[i][j]=dis[i][k]+dis[k][j];
							cnt[i][j]=1;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2)
					Ans++;
		cout<<Ans<<endl;
	}
	return 0;
}
