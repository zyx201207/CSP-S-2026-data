#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],dis[5005][5005],cnt[5005][5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			cin>>n>>d;
			for (int i=1;i<=n;i++)
				cin>>a[i];
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					dis[i][j]=1e9,cnt[i][j]=0;
			int ans=0;
			for (int i=1;i<=n;i++)
			{
				dis[i][i]=0;
				cnt[i][i]=1;
				for (int j=i+1;j<=n;j++)
				{
					if(a[j]-d>a[j-1]) break;
					int k=lower_bound(a+i,a+j,a[j]-d)-a;
					dis[i][j]=dis[i][k]+1;
					cnt[i][j]=cnt[i][k];
					if(dis[i][k+1]+1==dis[i][j])
						cnt[i][j]+=cnt[i][k+1];
					if(k+2<j&&dis[i][k+2]+1==dis[i][j])
						cnt[i][j]+=cnt[i][k+2];
					if(cnt[i][j]==2)
						ans++;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}
