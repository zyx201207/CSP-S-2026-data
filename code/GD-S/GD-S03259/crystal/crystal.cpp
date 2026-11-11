#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++)
	{
		long long cnt=0;
		for(int i=j+1;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				if(cnt+(i-j)*(a[i]-a[i-1])<=m)cnt+=(i-j)*(a[i]-a[i-1]);
				else
				{
					cout<<i-j;
					return 0;
				}
			}
		}
	}
	cout<<n;
	return 0;
}
