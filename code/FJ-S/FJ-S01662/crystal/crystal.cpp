#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	bool man=true,fals=true;
	int c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)
			c=a[2]-a[1];
		if(i!=1&&a[i]-a[i-1]!=c)
			fals=false;
		if(a[i]!=i)
			man=false;
	}
	if(man)
	{
		cout<<min(m+1,n);
		return 0;
	}
	else if(fals)
	{
		long long s=min(m/c+1,n);
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1);
	int maxn=1;
	for(int i=2;i<=n;i++)
	{
		int nans=1;
		int l=m;
		for(int j=i-1;j>=1;j--)
		{
			if(l>=a[i]-a[j])
			{
				nans++;
				l-=(a[i]-a[j]);
			}
			maxn=max(maxn,nans);
		}
	}
	cout<<maxn;
	return 0;
}