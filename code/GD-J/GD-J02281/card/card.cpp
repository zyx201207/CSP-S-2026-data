#include<bits/stdc++.h>
using namespace std;
int a[500005],dp[500005],b[300005],c[300005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
    cin>>a[i];
    b[a[i]]++;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
	if(b[a[i-1]]!=1)
	{
	dp[i]=1;
	b[a[i-1]]--;
	}
	else
	{
	dp[i]=0;
	}
	}
	for(int i=1;i<=n;i++)
	{
	if(dp[i]==1)
	{
	d[a[i]]++;
	}
	else
	{
	int cnt=i;
	for(int j=1;j<i;j++)
	{
	if(b[a[j]]!=1)
	{
	cnt--;
	}
	}
	c[a[i]]=max(d[a[i]],cnt);
	}
	}
	for(int i=1;i<=n;i++)
	{
	c[a[i]]=max(d[a[i]],c[a[i]]);
	}
	for(int i=1;i<=m;i++)
	{
	cout<<c[i]<<' ';
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
