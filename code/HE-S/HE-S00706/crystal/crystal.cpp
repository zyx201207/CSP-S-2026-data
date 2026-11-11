#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int maxx=-1;
int main()
{
//	/*
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	*/
	cin>>n>>m;
	long long x1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++)
	{
		x1+=(i-1)*(a[i]-a[i-1]);//
		while(x1>m)
		{
			x1-=a[i]-a[l];
			l++;
		}
		maxx=max(maxx,(i-l+1));
	}
	cout<<maxx;
	return 0;
}

