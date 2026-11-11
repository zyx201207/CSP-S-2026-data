#include<bits/stdc++.h>
using namespace std;
int a[500001],f[300001],dp[300001];
int d[300001],de[300001];
vector<int>dep[300001];
int main()                   
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[a[i]]++;
	}
	f[a[n]]=-1;
	d[a[n]]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(f[a[i]]==0)
		{
		f[a[i]]=a[i+1];
		d[a[i]]=d[a[i+1]]+1;
		dep[d[a[i]]].push_back(a[i]);
		de[d[a[i]]]++;
		}
	}
	for(int i=300000;i>=2;i--)
	{
		for(int l=0;l<de[i];l++)
		{
			dp[f[dep[i][l]]]+=dp[dep[i][l]];
		}
	}
	for(int i=1;i<=m;i++)
	cout<<dp[i]<<" ";
	return 0;
}
