#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[555555];

ll read()
{
	ll x;
	scanf("%lld",&x);
	return x;
}

ll cnt(int k)
{
	ll tot=0,ans=0;
	for(int i=k-1;i>0;i--)
	{ 
		tot+=a[k]-a[i];
//		cout<<tot<<"@ "<<ans<<"* \n";//
		if(tot<m)
		{
			ans++;
			if(i==0)
			{
				return ans;
				break;
			}
		}
		else if(tot==m)
		{
			ans++;
			return ans;
			break;
		}
		else
		{
			return ans;
			break;
		}
	}
}

int main()
{
	freopen("crystal.in","r",stdin);//
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		a[i]+=1e5;
	}
	sort(a+1,a+n+1);
	ll maxx=-1;
	for(int i=2;i<=n;i++)
	{
		ll ans=cnt(i);
		ans++;
//		cout<<ans<<"\n";//
		if(ans>maxx)
		{
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
