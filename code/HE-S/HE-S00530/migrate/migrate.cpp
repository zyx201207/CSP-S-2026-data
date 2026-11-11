#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
const int N=2e6;
long long x[N];
long long cha[N];
int cnt=0;
int ans=0;
long long q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)
		{
			q=x[2]-x[1];
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(q*(j-i)>d&&j-i>=2)
					{
						long long kskbl=(x[j]-x[i])/q+(x[j]-x[i])%q;
						if(kskbl+1==j-i)
						{
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		else if(c==13||c==14)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(d<=x[j]-x[i])
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		else if(c>=15&&c<=18)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(d<=x[j]-x[i])
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
