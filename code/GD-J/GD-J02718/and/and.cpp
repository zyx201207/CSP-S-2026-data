#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool s(int a,int b)
{
	return a>b;
}
int d(int m)
{
	int x=a[0]&a[1];
	for(int i=2;i<m;i++)
	{
		x&=a[i];
	}
	return x;
}
int main()
{
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,s);
	cout<<d(m);
	return 0;
}
