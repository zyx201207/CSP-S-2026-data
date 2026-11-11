#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],is[2000005];
int nxt[2000005],lst[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int p=1;
		a[0]=LONG_LONG_MIN,a[n+1]=LONG_LONG_MAX;
		for(int i=1;i<=n;i++)
		{
			while(a[i]+d>=a[p+1]) p++;
			nxt[i]=p;
		}
		p=n;
		for(int i=n;i>=1;i--)
		{
			while(a[i]-d<=a[p-1]) p--;
			lst[i]=p;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=i;k<=j;k++) is[k]=0;
				int flag=0;
				for(int k=i;k<=j;)
				{
					is[k]=1;
					k=nxt[k];
					if(k==nxt[k])
					{
						if(k<j) flag=-1;
						break;
					}
				}
				if(flag==-1) continue;
				for(int k=j;k>=i;)
				{
					if(!is[lst[k]]&&lst[k]>=i)
					{
						if(flag)
						{
							flag=0;
							break;
						}
						if(!is[lst[k]+1])
						{
							flag=0;
							break;
						}
						flag=1;
					}
					k=lst[k];
					if(k==lst[k])
					{
						if(k>i) flag=0;
						break;
					}
				}
				ans+=flag;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
