#include<iostream>
#include<cmath>
#define ll long long
#define un unsigned
using namespace std;
const int N=5e5+5;
ll a[N],n,sum,ans;
un ll m;
ll maxx(ll a,ll b)
{
	if(a>b)
	{
		return a;
	}else
	{
		return b;
	}
}
void dfs(int cnt)
{
	if(cnt==0)
	{
		ll ma=0;
		for(int i=1;i<=n;i++)
		{
			ll mm=0;
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					if(a[i]==a[j])
					{
						mm++;
					}
				}
			}
			ma=maxx(ma,mm);
		}
//		cout<<ans<<endl;
		ans=maxx(ma,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]++;
		dfs(cnt-1);
		a[i]--;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<=15)
	{
		dfs(m);
		cout<<ans+1;
		return 0;
	}else
	{
		ll head=a[1];
		ll pre=abs(a[2]-head);
		for(int i=1;i<=n;i++)
		{
			un ll va=abs((a[i]+head)/2*i);
			if(va>m)
			{
				cout<<i-1;
				return 0;
			}
		}
		return 0;
	}
}
