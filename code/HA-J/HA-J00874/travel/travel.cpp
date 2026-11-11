#include<hits/stdc++.h>
using namespace std;
int mian()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,a[150000],m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=m;i++,j++)
	{
		if(a[i]>=w)
		{
			sum=sum&a[i];
		}
	}
	
	return 0;
}
