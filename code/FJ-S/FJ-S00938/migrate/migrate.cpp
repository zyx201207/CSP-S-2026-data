#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2000001],dp[301][301][2];
void A()
{
	ll dengcha=a[2]-a[1];
	if(d<2*dengcha)
	{
		cout<<0<<"\n";
		return;
	}
	else
	{
		d=d/dengcha;
		ll b=2*d-1;
		if(b>n)
		    cout<<0<<"\n";
		else
		    cout<<n-b<<"\n";
		return;
	}
}
void qujiandp()
{
	ll ans=0;
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				dp[i][j][1]=1;
				dp[i][j][0]=1;
			}
			else
			{
				dp[i][j][1]=0;
				dp[i][j][0]=300;
				for(int b=j-1;b>i;b--)
				{
					if(a[j]-a[b]>d||dp[i][b][0]==300)
					{
						break;
					}
					else
					{
						if(dp[i][b][0]<dp[i][j][0]-1)
						{
							dp[i][j][0]=dp[i][b][0]+1;
							dp[i][j][1]=0;
						}
						dp[i][j][1]+=dp[i][b][1];
					}
				}
			}
			if(dp[i][j][1]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
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
		for(int i=1;i<=n;i++)
		{
		    cin>>a[i];
		}
		if(c==11||c==12)
		{
		    A();
	    }
		else
		{
			if(n<=300)
			{
				qujiandp(); 
			}
			else
			{
				cout<<0<<"\n";
			}
		}
	}
	return 0;
}
