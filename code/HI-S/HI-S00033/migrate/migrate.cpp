#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ci=const int;

ci N=305;
namespace Qwq
{
	int c,t;
	ll dp[N][N][N];  
	int nxt[N],pre[N];
	int ans;
	int n,d;
	int x[N];
	void mian()
	{
		int i,j,k,l;
		cin>>c>>t;
		while(t--)
		{
			cin>>n>>d;
			for(i=1;i<=n;i++) cin>>x[i];
			for(i=1;i<=n;i++)
			{
				for(j=1;j<i;j++)
				{
					if(x[i]-x[j]<=d)
					{
						pre[i]=j;
						break;
					}
				}
			}
			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					if(x[j]-x[i]>d)
					{
						nxt[i]=j-1;
					}
				}
			}
			for(i=1;i<=n;i++)
			{
				dp[i][i][0]=1;
			}
			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					for(k=1;k<=n;k++)
					{
						for(l=pre[j];l<=nxt[j];l++)
						{
							dp[i][j][k]+=dp[i][l][k-1];
						}
					}
				}
			}
			for(i=1;i<=n;i++)
			{
				for(j=i+1;j<=n;j++)
				{
					for(k=1;k<=n;k++)
					{
						if(dp[i][j][k]&&dp[i][j][k]==2)
						{
							ans++;
							break;
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	Qwq::mian();
	return 0;
}

