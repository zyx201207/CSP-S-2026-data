#include <bits/stdc++.h>
using namespace std;

int a[500005],b[500005][1005],c[500005];
long long ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		ans=ans+(a[i+1]-a[i])*i;
		if(ans>m)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
