#include<iostream>
#include<algorithm>
using namespace std;
#define ll unsigned long long

int n, m;
int a[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out","w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}sort(a+1,a+n+1);
	int r=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		r&=a[i];
	}cout<<r;
	return 0;
 } 
