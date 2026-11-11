#include<bits/stdc++.h>
using namespace std;
long long int mm[10101][10101],last[1010101],a[1010101],sum[1010101];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
	long long int n,m;
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int T=1;T<=n;T++)
	{
		for(long long int j=1;j<=m;j++)
		{
			memset(mm[j],0,sizeof(mm[j]));
		}
		memset(last,0,sizeof(last));
		map<long long int,long long int> mp;
		for(long long int i=T;i<=n;i++)
		{				
			mp[a[i]]++;
			if(mp[a[i]]!=1)				
			{
				for(long long int j=1;j<=m;j++)
				{
					mm[j][i]=mm[j][last[a[i]]];
				}
			}
			else
			{
				for(long long int j=1;j<=m;j++)
				{
					mm[j][i]=mm[j][i-1];
				}
				mm[a[i]][i]++;
			}
			for(long long int j=1;j<=m;j++)
			{
				mp[j]=0;
				if(mm[j][i]>0)
				{
					mp[j]++;
				}
			}
			last[a[i]]=i;
		}
		for(long long int j=1;j<=m;j++)
		{
			if(mm[j][n]>0)
			{
				sum[j]++;
			}
		}
	}
	for(long long int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	} 
}
