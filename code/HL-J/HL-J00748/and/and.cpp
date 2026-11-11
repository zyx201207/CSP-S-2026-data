#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int main()
{
	//freopen(and.in);
	//freopen(and.out);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[n];
	}
	sort(a+1,a+n+1);
	int k=1;
	while(k<a[n-m+1])
	{
		k=k*2;
	}
	cout<<k-1;
	return 0;
}