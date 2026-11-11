#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5+5;
ll a[N];
ll mx=-1;
ll ans1=pow(2,30)-1;
ll ans=pow(2,30)-1;
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		ans1=ans1&a[i];
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==2)
	{
		ll x=-1,y;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					y=a[i]&a[j];
					x=max(x,y);
				}
			}
		}
		cout<<x;
		return 0;
	}
	if(m==n-1)
	{
		ll x=-1,y=pow(2,30)-1;
		for(int i=1;i<=n;i++)
		{
			y=pow(2,30)-1;
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					y=y&a[j];
				}
			}
			x=max(x,y);
		}
		cout<<x;
		return 0;
	}
	if(m==n)
	{
		cout<<ans1;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
