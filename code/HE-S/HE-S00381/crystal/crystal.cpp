#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mi;
	if(n%2==1) mi=n/2+1;
	else mi=n/2;
	int b[n+5];
	for(int i=1;i<=n;i++)
	{
		if(i!=mi)
		{
			b[i]=abs(a[mi]-a[i]);
		}
	}
	sort(b+1,b+n);
	for(int i=1;i<=n;i++)
	{
		if(m>=b[i])
		{
			m-=b[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
	
}
