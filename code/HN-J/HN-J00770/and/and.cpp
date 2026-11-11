#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,int c)
{
	if(a==1||b==1)
	{
		return pow(2,c);
	}
	int s=0;
	if(a%2==1&&b%2==1)
	{
		s=pow(2,c);
	}
	return f(a/2,b/2,c+1)+s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],l;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==n)
	{
		l=a[1];
		for(int i=2;i<=n;i++)
		{
			l=f(l,a[i],0);
		}
		cout<<l;
	}
	else
	{
		cout<<a[n-m+1];
	}
	return 0;
}
