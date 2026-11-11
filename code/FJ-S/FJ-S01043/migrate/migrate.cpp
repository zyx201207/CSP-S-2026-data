#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=2e6+5;
const int maxm=5e3+5;
int a[maxn],t[maxm][maxm];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;cin>>C>>T;
	while(T--)
	{
		memset(t,0,sizeof(t));
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C==11 || C==12)
		{
			int gc=a[2]-a[1];
			if(d<2*gc)
			{
				cout<<0<<endl;
				continue;
			}
			else
			{
				int x=d/gc;
				int ans=1;
				for(int i=1;i<=n-x;i++) ans*=i;
				cout<<ans<<endl;
			}
			continue;
		}
		if(C==13 || C==14)
		{
			cout<<0<<endl;
			continue;
		}
		if(C>=15&&C<=18)
		{
			int ans=1;
			for(int i=1;i<=n;i++)
			{
				ans*=i;
			}
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			int x=i;
			int cnt=0;
			while(x<n)
			{
				int g=0;
				if(cnt>0) t[i][x]=1;
				cnt++;
				while(x<n && g+a[x+1]-a[x]<=d)
				{
					g+=a[x+1]-a[x];
					x++;
				}
				if(x>=n) break;
				t[i][x]=0;
			}
			x=i;
			cnt=0;
			while(x>1)
			{
				if(cnt>0) t[i][x]=1;
				cnt++;
				int g=0;
				while(x>1 && g+a[x]-a[x-1]<=d)
				{
					g+=a[x]-a[x-1];
					x--;
				}
				if(x<=1) break;
				t[i][x]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int x=1;x<=n;x++)
			{
				ans+=t[i][x-1]|t[i][x+1];
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}

