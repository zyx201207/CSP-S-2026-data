#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("card.in","r",stdin);//Trick||Treat!
    freopen("card.out","w",stdout);
	ll n,m,a[6]={},la=-1,ha=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]%2)
	{
		for(int i=1;i<=n;i++)
		{
			ha=0;
			la=-1;
			for(int j=i;j<=n;j++)
			{
				if(a[j]==2)
				{
					ha++;
				}
				else
				{
					if(la==-1)
					{
						la=j;
					}
					else
					{
						ha=ha-(j-la-1);
						la=-1;
					}
				}
				
			}
			if(ha)
			{
				ans++;
			}
		}
		cout<<n<<' '<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ha=0;
			la=-1;
			for(int j=i;j<=n;j++)
			{
				if(a[j]==1)
				{
					ha++;
				}
				else
				{
					if(la==-1)
					{
						la=j;
					}
					else
					{
						ha=ha-(j-la-1);
						la=-1;
					}
				}
			}
			if(ha)
			{
				ans++;
			}
		}
		cout<<ans<<' '<<n;
	}
    return 0;
}

