#include<bits/stdc++.h>
using namespace std;
long long a[500010],t[500010];
long long dp[500010],addx[500010],cnt[500010];
long long ans[300010];
long long n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		//long long now=a[i];
		dp[i]=t[a[i]]+1;
		addx[i]=a[i];
		cnt[i]=1;
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<dp[i]<<",";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<addx[i]<<",";
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		ans[ addx[i] ]+=cnt[i];
		cnt[ dp[i] ]+=cnt[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
