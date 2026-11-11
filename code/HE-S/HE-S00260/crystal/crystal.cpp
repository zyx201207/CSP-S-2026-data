#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int sum=0,j;
		for (j=i+1;j<=n;j++)
		{
			sum+=a[i]-a[j];
		}
		if(sum<=m)
		{
			cout<<n-i+1;
			return 0;
		}
	}
	return 0;
}
