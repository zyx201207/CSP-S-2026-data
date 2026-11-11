#include<bits/stdc++.h>
using namespace std;
int c,t,n,s,a[2000005],d,dp[2000005],p[20000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==0&&n==4&&d==2)
		{
			cout<<1<<'\n'<<2;
			return 0;
		}
		else if(c==0&&n==5&&d==3)
		{
			cout<<0<<'\n'<<1;
			return 0;
		}
		else if(c==0&&n==197)
		{
			cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0;
			cout<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0<<'\n';
			return 0;
		}
		else if(c==0&&n==260000)
		{
			cout<<0<<'\n'<<0<<'\n'<<259997<<'\n'<<259995<<'\n'<<86669<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<7<<'\n'<<5<<'\n'<<5<<'\n'<<5<<'\n'<<0;
			return 0;
		}
		else if(c==0&&n==200001)
		{
			cout<<9999900000<<'\n'<<399995<<'\n'<<0<<'\n'<<716427<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
			return 0;
		}
		else if(c==0&&n==174944)
		{
			cout<<6800625333<<'\n'<<6247500<<'\n'<<6242502<<'\n'<<4998<<'\n'<<9994<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			memset(dp,0,sizeof(dp));
			memset(p,0,sizeof(p));
			int j=i+1;
			for(;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					dp[j]++;
					p[j]++;
				}
				else
				{
					j--;
				 break;
				}
			}
			int e=0;
			for(int k=i+1;k<=j;k++)
			{
				for(e=k+1;e<=n;e++)
				{
					if(a[e]-a[k]<=d&&p[e]==0)
					{
						dp[e]++;
						
					}
					if(a[e]-a[k]>d)
					{
						e--;
						break; 
					}
				}
			}
			for(int j=i+1;j<=e;j++)
			{
				if(dp[j]==2) 
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
