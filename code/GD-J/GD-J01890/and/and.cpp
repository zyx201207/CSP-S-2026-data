#include <bits/stdc++.h>
using namespace std;
int m,n,cnt;
int a[200005],ma,sum,mann;
int dp[2010][2010];
bool bd(int x)
{
	while(x)
	{
		if(x%2!=1)	return false;
		x/=2;
	}
	return true;
}
bool cmp(int x,int y)
{
	if(bd(x)) return x>y;
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ma=max(ma,a[i]);
		sum=sum&a[i];
		if(bd(a[i])) 
		{
			cnt++;
			mann=max(mann,a[i]);
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) cout<<ma;
	else if(m==n) cout<<sum;
	else if(m==2)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=i&j;
				k=max(k,dp[i][j]);
			}
		}
		cout<<k;
	}
	else
	{
		cout<<mann;
	}
	return 0; 
}
