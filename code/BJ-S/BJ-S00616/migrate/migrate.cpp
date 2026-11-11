#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1110000],s[1110000],b[5100][5100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=a[i]+s[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			int cnt=0,t=0;
			for(int j=1;j<=n;j++)
			{
				if(b[i][j]!=0)
				{
					t=j;
					break;
				}
			}
			for(int j=i+1;j<=n;j++)
			{
				cnt+=a[j]-a[j-1];
				if(cnt<=d)
				{
					
					b[i][t+1]++;
				}
				else
				{
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=j;k++)
				{
					if(b[i][j]-b[i][k]==2)
					{
						ans++;
					}
				}
				if(b[i][j]!=0&&b[i][j]==2)
				{
					ans++;
					break;
				}
				else if(b[i][j]!=0)
				{
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
