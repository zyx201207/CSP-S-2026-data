#include<bits/stdc++.h>
using namespace std;
long long a[200005],qpow[32],n,m;
bool mp[200005][32],v[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	qpow[0]=1;
	for(int i=1;i<=30;i++)
	{
		qpow[i]=qpow[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int k=a[i];
		for(int j=30;j>=0&&k;j--)
		{
			if(k>=qpow[j])
			{
				mp[i][j]=1;
				k-=qpow[j];
			}
		}
	}
	for(int i=30;i>=0;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(v[j])
			{
				continue;
			}
			if(mp[j][i])
			{
				sum++;
			}
		}
		if(sum>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(!mp[j][i])
				{
					v[j]=1;
				}
			}
		}
	}
	long long ans=pow(2,31)-1,j=1;
	for(int i=1;i<=n,j<=m;i++)
	{
		if(!v[i])
		{
			ans&=a[i];
			j++;
		}
	}
	if(j<m)
	{
		cout<<0;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
