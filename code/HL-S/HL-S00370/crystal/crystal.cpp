#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(100000,0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll temp=a[2]-a[1];
	bool t2=0,flag=0;
	for(int i=3;i<=n;i++)
	{
		if(temp!=a[i]-a[i-1])
		{
			flag=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i)
		{
			t2=1;
		}
	}
	ll i=a[2]-a[1],k=1;
	bool tflag=1;
	if(flag==0)
	{

		if(t2==0)
		{
			while(m>=0)
			{

				m-=k;
				if(m<0)
				{
					break;
				}
				else
				{
					cnt++;
					k++;
				}

			}
		}
		else
		{
			while(m>=0)
			{

				if(k>n)
				{
					break;
				}

				for(ll j=1;j<=k;j++)
				{
					m-=i;
					if(m<0)
					{
						tflag=0;
					}
				}
				cout<<k<<" "<<m<<" "<<endl;
				if(tflag==1)
				{
					cnt++;
				}
				else
				{
					break;
				}

				k++;
			}
		}
	}
	else
	{
		ll tar=a[2]-a[1];
		while(m>=0)
		{
			if(k>n)
			{
				break;
			}
			for(ll j=1;j<=k;j++)
			{
				m-=tar;
				if(m<0)
				{
					tflag=0;
				}
			}
			if(tflag==1)
			{
				cnt++;
			}
			else
			{
				break;
			}
			k++;
			if(k+1<=n)
			{
				tar=a[k+1]-a[k];
			}
		}
	}
	cout<<cnt;
	return 0;
}
