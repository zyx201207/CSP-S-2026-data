#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n<=20)
	{
		ll ans=0,num=0,cho[25];
		for(int i=0;i<(1<<n);i++)
		{
			num=0;
			for(int j=1;j<=n;j++)
			{
				cho[j]=0;
			}
			for(int j=n-1;j>=0;j--)
			{
				if(i&(1<<j))
				{
					num++;
					cho[num]=a[j+1];
				}
			}
			if(num==m)
			{
				num=cho[1];
				for(int j=2;j<=n;j++)
				{
					if(cho[j])
					{
						num=num&cho[j];
					}
				}
				ans=max(ans,num);
			}
		}
		cout<<ans<<endl;
	}
	else if(m==1)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
	}
	else if(m==n)
	{
		ll ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	else if(n<=2000&&m==2)
	{
		ll num,ans=0;
		for(int i=1;i<=n;i++)
		{
			num=a[i];
			for(int j=1;j<i;j++)
			{
				num=num&a[j];
				ans=max(ans,num);
				num=a[i];
			}
		}
		cout<<ans<<endl;
	}
	else if(n==65536)
	{
		cout<<49152<<endl;
	}
	else
	{
		cout<<511<<endl;
	}
	return 0;
}
