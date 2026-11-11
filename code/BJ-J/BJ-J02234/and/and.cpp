#include <bits/stdc++.h>
using namespace std;
int a[200010];

int Ttt(int x)
{
	int c=0,v=1;
	while (x)
	{
		c=c+x%2*v;
		x/=2;
		v*=10;
	}
	return c;
}

int ttT(int x)
{
	int c=0,v=1;
	while (x)
	{
		c=c+x%10*v;
		x/=10;
		v*=2;
	}
	return c;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0,last=0;
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;++i)
	{
		for (int j=2;j<=n;++j)
		{
			maxn=max(ttT(Ttt(last)&Ttt(i-1)),ttT(Ttt(last)&Ttt(i)));
		}
		last=maxn;
	}
	cout<<maxn;
	return 0;
}