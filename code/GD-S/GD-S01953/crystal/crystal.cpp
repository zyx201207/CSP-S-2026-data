#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long m;
long long a[500010],sa[500010];
bool check(int l)
{
	for(int i=1; i<=n-l+1; i++)
	{
		if(m>=a[l+i-1]*l-(sa[i+l-1]-sa[i-1]))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
	{
		sa[i]=sa[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << r << endl;
	return 0;
} 
