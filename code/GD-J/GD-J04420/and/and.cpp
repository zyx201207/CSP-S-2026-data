#include<bits/stdc++.h>
using namespace std;
int n,m,l,o,k=0;
int a[200005],s[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		s[i]=a[i];
		if (a[i]>k)
		{
			k=a[i];
		}
	}
	l=a[1];
	for (int i=1;i<n;i++)
	{
		s[i]&=s[i-1];
		l&=a[i];
	}
	o=s[n-2];
	if (m==n)
	{
		cout<<s[n];
		return 0;
	}
	else if (m==1)
	{
		cout<<k;
		return 0;
	}
	else if (m==n-1)
	{
		cout<<max(l,o);
		return 0;
	}
}
