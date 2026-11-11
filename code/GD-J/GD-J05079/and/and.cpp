#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=2e5+10; 
ll n,m,a[N],f[N],ans=0;
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b & 1)
		{
			ans = ans * a;
		}
		a = a * a;
		b/=2;
	}
	return ans;
}
ll dfs(ll sum,ll cnt)
{
	if(cnt == m)
	{
		ans=max(ans,sum);
		return ans;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			sum = sum & a[i];
			f[i]=1;
			cnt++;
			dfs(sum,cnt);
			f[i]=0;
			cnt--;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool fb=false;
	for(ll i=0;i<=31;i++)
	{
		if(qpow((ll)2,i)==n)
		{
			fb=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i] != i-1)
		{
			fb=false;
		}
	}
	if(m==1)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout << ans << endl;
	}
	else if(m==2)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i] & a[j]);
			}
		}
		cout << ans << endl;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans << endl;
	}
	else if(fb==true)
	{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans = ans & a[i];
		}
		cout << ans << endl;
	}
	else if(n<=20)
	{
		ans=0;
		dfs(2147483647,0);
		cout << ans << endl;
	}
	else
	{
		sort(a+1,a+n+1);
		ll ans=a[n];
		for(int i=n;i>=n-m+1;i--)
		{
			ans = ans & a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
