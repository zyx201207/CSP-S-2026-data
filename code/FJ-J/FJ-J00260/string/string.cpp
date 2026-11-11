#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r;
struct zf
{
	long long gs=0;
	char zm;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].gs>>a[i].zm;
	}
	l=1;
	r=n;
	while(l<=r)
	{
		if (a[l].zm != a[r].zm)
		{
			ans++;
		}
		a[l].gs--;
		a[r].gs--;
		if (a[l].gs<=0)
		{
			l++;
		}
		if (a[r].gs<=0)
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
//2 2 a 3 a
