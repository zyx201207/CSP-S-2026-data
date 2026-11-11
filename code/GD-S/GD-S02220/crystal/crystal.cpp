#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],mid,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	mid=n/2;
	if(n%2==1)	mid++;
	
	for(int i=n;i>=mid;i--)
	{
		if(a[i]==a[mid])	ans++;
	}
	for(int i=mid-1;i>=1;i--)
	{
		long long x=a[mid]-a[i];
		if(m>=x)
		{
			m-=x;
			ans++;
		}
		else
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
