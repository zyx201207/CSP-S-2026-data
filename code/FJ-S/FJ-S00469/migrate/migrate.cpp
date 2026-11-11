#include<bits/stdc++.h>
using namespace std;
long long x[5005],dis[5005],cnt[5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,T,n,l,r,ans;
	long long d;
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			memset(cnt,0,sizeof cnt);
			memset(dis,0,sizeof dis);
			l=i;
			r=i;
			cnt[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				while(x[j]-x[l]>d)
				{
					l++;
				}
				dis[j]=dis[l]+1;
				for(int k=l;k<j;k++)
				{
					if(dis[k]+1==dis[j])
					{
						cnt[j]+=cnt[k];
					}
				}
				if(cnt[j]==2)
				{
					ans++;
				}
				if(cnt[j]>2 and c>6)
				{
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
