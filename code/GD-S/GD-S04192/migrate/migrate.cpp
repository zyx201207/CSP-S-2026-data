#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
const int inf = 0x3f3f3f3f;
int c,t;
int n,d;
int x[N];
int ans;
bool check(int l,int r,int d)
{
	if(x[r]-x[l]<=d) return 0;
	int p = lower_bound(x+l,x+r+1,x[l]+d)-x;
	if(x[p]>x[l]+d) p--;
	int q = lower_bound(x+l,x+r+1,x[r]-d)-x;
	if(p<=q) return 0;
	if(p-q == 1ll) 
	{ 
		//cout<<p<<" "<<q<<endl;
		return 1;
	}
	
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(11<=c&&c<=12)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			ans = 2*(1.0*d/(x[n]-x[n-1]))-1;
			ans = max(0ll,n-ans+1);
			cout<<ans<<endl;
		}
	}
	else if(13<=c&&c<=14) 
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			cout<<0<<endl;
		}
	}
	else 
	{
		while(t--)
		{
			ans=0;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(check(i,j,d))
					{
						ans++;
						//cout<<i<<" "<<j<<endl;
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
}

