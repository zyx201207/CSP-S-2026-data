#include <iostream>
using namespace std;

#define int long long
int arr[2000005];
int dis[2000005];
int minn[2000005];
int cnt[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		if(c==11 || c==12)
		{
			int D=arr[2]-arr[1];
			int k=d/D;
			if(k<=1)
			{
				cout<<0;
			}else
			{
				cout<<max(0ll,n-(2*k-1));
			}
			cout<<'\n';
			continue;
		}
		int ans=0;
		for(int l=1;l<=n;l++)
		{
			int ll=l;
			dis[l]=0;
			for(int r=ll;r<=n;r++)
			{
				while(ll<=r && arr[r]-arr[ll]>d)
				{
					ll++;
				}
				dis[r]=dis[ll]+1;
				minn[r]=ll;
			}
			cnt[l]=1;
			for(int r=l+1;r<=n;r++)
			{
				cnt[r]=0;
				for(int k=max(l,minn[r]);k<=min(r-1,minn[r]+3);k++)
				{
					if(dis[k]==dis[r]-1)
					{
						cnt[r]+=cnt[k];
					}
				}
				ans+=cnt[r]==2;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
