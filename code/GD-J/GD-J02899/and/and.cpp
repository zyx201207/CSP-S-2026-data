#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a[200005]={0},ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	ans=a[1];
	ll num=1,i=2;
	while(num!=m)
	{
		if((ans&a[i])!=0)
		{
			ans&=a[i];
			num++;
		}
		i+=1;
	}
	cout<<ans;
	return 0;
} 
