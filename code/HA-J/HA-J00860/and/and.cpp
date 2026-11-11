#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10005],maxn=-10,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=maxn)
		{
			maxn=a[i];
		}
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		sort(a+1,a+n+1);
		cout<<a[n-2];
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n-2];
	}
	return 0;	
}
