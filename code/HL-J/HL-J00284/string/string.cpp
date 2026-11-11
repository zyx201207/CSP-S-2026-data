#include <bits/stdc++.h>
using namespace std;
struct mmm
{
	long long x;
	char c;
};
int n;
long long num;
mmm a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		if (a[l].x>a[r].x)
		{
			if (a[l].c!=a[r].c)
				num+=a[r].x;
			a[l].x-=a[r].x;
			r--;
		}
		else if (a[l].x<a[r].x)
		{
			if (a[l].c!=a[r].c)
				num+=a[l].x;
			a[r].x-=a[l].x;
			l++;
		}
		else
		{
			if (a[l].c!=a[r].c)
				num+=a[r].x;
			l++;
			r--;
		}
	}
	cout <<num;
	return 0;
}
