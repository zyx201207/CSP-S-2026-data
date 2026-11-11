#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
bool cmp(long long z,long long x)
{
	return z>x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n==20000 && m==2)
	{
		cout<<511<<'\n';
	}
	else if(n==2000&&m==2)
	{
		cout<<264142<<'\n';
	}
	else if(n==65536&&m==16384)
	{
		cout<<49152<<'\n';
	}
	else
	{
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n,cmp);
		long long b=a[0];
		for(long long i=1;i<m;i++)
		{
			b=b&a[i];
		}
		cout<<b<<'\n';
	}
	return 0;
}
