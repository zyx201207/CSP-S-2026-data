#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	if(a[0]==a[n-1])cout<<n;
	else if(a[n-2]==a[n-1]-1)
	{
		int c=0;
		for(int i=1;i<n;i++)
		{
			c+=i;
			if(c+i+1>m)
			{
				cout<<c;
				return 0;
			}
		}
	}
	return 0;
}
