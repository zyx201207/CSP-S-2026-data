#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[12345678],s=0,sum=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		s=a[1];
		for(int i=2;i<=n;i++)
		{
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
		    sum=a[i]&a[j];
			s=max(s,sum);
		}
	}
	cout<<s;
	return 0;
}
