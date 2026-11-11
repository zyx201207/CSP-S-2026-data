#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int b[100001][100001];
int d=0,s;
	void zx(int y){	
		while(s>0)
		{
			e[++d]=y%2;
			y/=2;
		}
		for(int j=d;j>=1;j--)
		{
			b[e]+=char(y[j]);
		}
	}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m;i--)
	{
		er(n-i+1,a[i]);
	}
	return 0;
}
