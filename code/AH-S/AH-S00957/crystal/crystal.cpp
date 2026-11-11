#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		if(a[i]==a[i+1])
		{
			s++;
			m=m-1;
		}
		if(a[i+1]-a[i]<=m)
		{
			m=m-(a[i+1]-a[i]);
			s++;
		}
	}
	cout<<s;
	return 0;
}
