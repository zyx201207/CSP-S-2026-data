#include <bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n-1;j++)
		{
			ma=max(a[i]&a[j+1],ma);
		}
	}
	cout<<ma;
}
