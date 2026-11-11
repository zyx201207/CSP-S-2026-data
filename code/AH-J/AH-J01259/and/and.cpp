#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long b=65535;
	for(int i=0;i<m;i++)
	{
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
