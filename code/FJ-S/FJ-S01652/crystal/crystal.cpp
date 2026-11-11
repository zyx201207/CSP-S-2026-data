#include<bits/stdc++.h>
using namespace std;
long long n,m,o=0;
long long a[500010],s[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	s[1]=0;
	for(long long i=2;i<=n;i++)
	{
		s[i]=(i-1)*(a[i]-a[i-1])+s[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			o=max(o,(j-i+1)*((s[j]-s[i-1])<=m));
		}
	}
	cout<<o;
	return 0;
}
