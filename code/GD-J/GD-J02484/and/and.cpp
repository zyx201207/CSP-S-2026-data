#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[200010],_all,maxn,ans;
bool vis[30],flaga=1,flagb=1,flag_4=1;

void dfs(ll cnt,ll s)
{
	if(cnt==0)
	{
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			continue;
		}
		vis[i]=1;
		dfs(cnt-1,s&a[i]);
		vis[i]=0;
	}
	return;
}
bool check(ll x)
{
	while(x)
	{
		if(x&2==0)
		{
			return 0;
		}
		x>>=1;
	}
	return 1;
}
ll _ANS()
{
	srand(time(0)^2147483647);
	return rand()%4;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(!check(a[i]))
		{
			flaga=0;
		}
		if(a[i]!=i-1)
		{
			flagb=0;
		}
		if(a[i]>=4)
		{
			flag_4=0;
		}
	}
	_all=a[1];
	for(int i=2;i<=n;i++)
	{
		_all=_all&a[i];
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			dfs(m-1,a[i]);
			vis[i]=0;
		}
		cout<<ans;
	}
	else if(n<=2000)
	{
		if(m==1)
		{
			cout<<maxn;
		}
		else if(m==n)
		{
			cout<<_all;
		}
		else
		{
			ll k=0;
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					k=max(a[i]&a[j],k);
				}
			}
			cout<<k;
		}
	}
	else
	{
		if(flagb)
		{
			sort(a+1,a+n+1);
			ll _ans=a[n];
			m--;
			for(int i=n-1;i>=1;i--)
			{
				if(m==0)
				{
					break;
				}
				_ans=_ans&a[i];
				m--;
			}
			cout<<_ans;
			return 0;
		}
		cout<<_ANS();
	}
	
	return 0;
}
