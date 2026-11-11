#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int dp[100010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dp[1]=a[1];
	
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
			return 0;
		}
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	
	return 0;
}
