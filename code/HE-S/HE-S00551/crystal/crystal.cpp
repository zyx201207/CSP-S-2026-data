#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int mx=0;
	int s=0;
	int nw=0;
	for(int i=0;i<n;i++)
	{
		nw+=(i-s)*(a[i]-a[i-1]);
		while(nw>m)
		{
			nw-=(a[i]-a[s]);
			s++;
		}
		if((i-s+1)>mx)
		{
			mx=(i-s+1);
		}
	}
	cout<<mx;
	return 0;
}
