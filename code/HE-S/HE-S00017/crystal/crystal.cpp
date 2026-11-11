#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull n,m;
ll a[1000005];
ll num[1000005];
ll mina=1e12;
ll maxb=-1e12;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=a[i])
		{
			flag=0;
		}
	}
	sort(a+1,a+n+1);
	int last=a[1];
	int l=1;
	int maxn=-1;
	if(flag)
	{
		m-=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]*i<=m)
			{
				l++;
				m-=a[i]*i;
			}
			else
			{
				cout<<l;
				return 0;
			}
		}
		cout<<l;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		mina=min(mina,a[i]-a[i-1]);
		maxb=max(maxb,a[i]-a[i-1]);
	}
	if(mina==maxb)
	{
		for(ull i=2;i<=n;i++)
		{
			if(ull((i+1)/2*i)<=m)
			{
				l++;
			}
			else
			{
				cout<<l;
				return 0;
			}
		}
		cout<<l;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]*l-last<=m)
		{
			last+=a[i];
			l++;
			maxn=max(maxn,l);
		}
		else
		{
			l=1;
			last=a[i];
		}
	}
	cout<<maxn<<endl;
	return 0;
}
