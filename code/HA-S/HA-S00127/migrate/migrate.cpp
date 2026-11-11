#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000100;
int c,T,n,d,x[N],cnt[N],dis[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int ans=0,ma=1;
		for(int i=1;i<=n;i++)
		{
			memset(dis+i,0x3f,(n-i+2)*sizeof(int));
			//memset(cnt+i,0x3f,(n-i+2)*sizeof(int));
			cnt[i]=1;
			dis[i]=0;
			bool f=1;
			int j=i;
			for(;j<=n;j++)
			{
				if(cnt[j]==2)
				ans++;
				else if(cnt[j]==0)
				{
					break;
				}
				int k=j+1;
				for(;k<=n;k++)
				{
					if(x[k]-x[j]<=d)
					{
						if(dis[k]>dis[j]+1)
						{
							dis[k]=dis[j]+1;
							cnt[k]=cnt[j];
						}
						else if(dis[k]==dis[j]+1)
						{
							cnt[k]+=cnt[j];
						}
						if(cnt[k]<3)
							f=0;
					}
					else
					break;
				}
				if(f)
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
