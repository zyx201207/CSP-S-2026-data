#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long mp[505][505];
long long dp[505][505];
vector<int> belongs[500005];
vector<long long> changec[500005];
int c,n,m,d,q;
int main()
{
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
 	memset(mp,0x3f,sizeof(mp));
 	memset(dp,0x3f,sizeof(dp));
 	cin >> c >> n >> m >> d >> q;//c,d is useless
 	for(int i = 1;i<=m;i++)
 	{
 		cin >> w[i];
	}
	for(int i = 1;i<=n;i++)
	{
		mp[i][i]=0;
		int k;
		cin >> k;
		for(int j = 1;j<=k;j++)
		{
			int a,t;
			cin >> a >> t;
			belongs[a].push_back(i);
			changec[a].push_back(t);
		}
	}
	for(int i = 1;i<=m;i++)
	{
		int sz=belongs[i].size();
		if(sz<=1)continue;
		else
		{
			for(int j = 0;j<sz;j++)
			{
				for(int k = j+1;k<sz;k++)
				{
					mp[belongs[i][j]][belongs[i][k]]=min(changec[i][j]+changec[i][k],mp[belongs[i][j]][belongs[i][k]]);
					mp[belongs[i][k]][belongs[i][j]]=min(changec[i][j]+changec[i][k],mp[belongs[i][k]][belongs[i][j]]);
				}
			}
		}
	}
	for(int k = 1;k<=n;k++)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],mp[i][j]);
				dp[i][j]=min(dp[k][i]+dp[k][j],dp[i][j]);
			}
		}
	}
	for(int i = 1;i<=q;i++)
	{
		int s,t;
		cin >> s >> t;
		int sz1=belongs[s].size();
		int sz2=belongs[t].size();
		long long cur=0x5f5f5f5f5f5f5f5f;
		for(int j = 0;j<sz1;j++)
		{
			for(int k = 0;k<sz2;k++)
			{
				cur=min(cur,dp[belongs[s][j]][belongs[t][k]]+changec[s][j]+changec[t][k]);
			}
		}
		cout <<cur+w[s]+w[t] << '\n';
	}
 	return 0;
}

