#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[500005],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++)
	{
		if(a[i]!=a[i+1]&&m-a[i+1]+a[i]<0)
		{
			break;
		}
		if(a[i]!=a[i+1])
		{
			m=m-a[i+1]+a[i];
		}
		ans++;
	}
	cout<<++ans;
	return 0;
}
