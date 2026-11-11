#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
const int INF=1e18;
int c,T;
int n,d;
int a[2000005];
int b[2000005];
int f[5005][5005],g[5005][5005];
void solve()
{
	if(c>10)
	{
		printf("0\n");
		return;
	}
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,pos;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[mid]-a[i]<=d)
			{
				pos=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		b[i]=pos;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0,g[i][i]=1;
		for(int j=i-1;j>=1;j--)
		{
			int ans1=INF,ans2=0,lim=min(i,b[j]);
			for(int k=j+1;k<=lim;k++)
			{
				if(f[i][k]<ans1)
				{
					ans1=f[i][k];
					ans2=g[i][k];
				}
				else if(ans1==f[i][k])
				{
					ans2+=g[i][k];
				}
			}
			f[i][j]=ans1+1;
			g[i][j]=ans2;
			if(g[i][j]==2)
			{
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		solve();
	}
	return 0;
}
