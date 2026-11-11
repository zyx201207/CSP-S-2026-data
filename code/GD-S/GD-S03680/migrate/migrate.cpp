#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n;
ll d,le[2000100],pre[2000100],ans;
ll dp[5010][5010],no[5010],su[5010][5010];
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;ans=0ll;
		for(int i=1;i<=n;i++)cin>>le[i];
		for(int i=1,j=1;i<=n;i++)
		{
			while(le[i]-le[j]>d)j++;
			pre[i]=j;
		}
		if(n<=5000)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<i;j++)dp[i][j]=su[i][j]=0;
				if(pre[i]==i)continue;
				dp[i][i]=0;
				for(int j=1;j<pre[i];j++)
				{
					dp[i][j]=dp[pre[i]][j]+1;
				}
				for(int j=pre[i];j<i;j++)
				{
					dp[i][j]=1;
					su[i][j]=1;
					for(int k=1;k<pre[i];k++)
					{
						if(dp[j][k]+1==dp[i][k])su[i][k]+=su[j][k];
					}
				}
				for(int j=1;j<i;j++)if(dp[i][j] and su[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
