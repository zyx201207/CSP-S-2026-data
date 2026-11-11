#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,a[200005],l,r,x,y,ans=0,k;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	}
	l=1,r=n;
	while (l<=r)
	{
		if (x==0) x=a[l++];
		if (y==0) y=a[r--];
		k=min(x,y);
		if (c[l-1]!=c[r+1]) ans+=k;
		x-=k,y-=k;
	}
	cout << ans;
	return 0;
}
