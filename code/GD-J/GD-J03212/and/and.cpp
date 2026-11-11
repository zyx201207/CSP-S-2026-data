#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m+1;i--)
	{
		if(i==n)s+=a[i];
		else s&=a[i];
	}
	cout<<s;
} 
