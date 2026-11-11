#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
const int INF = 0x3f3f3f3f;
int dp[MAXN][MAXN],rt[MAXN][MAXN],x[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) 
	{
		int n,d,ans=0,cnt=0;
		cin>>n>>d;
		memset(dp,INF,sizeof dp);
		memset(rt,0,sizeof rt);
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			dp[i][i]=0;
		}
		
		for(int i=1;i<=n;i++)
		{
			int j=i-1;
			while(j>0 && x[i]-x[j]<=d)
			{
				for(int k=1;k<i;k++)
				{
					cnt++;
					if(dp[x[k]][x[j]]+1<dp[x[k]][x[i]])
					{
						dp[x[k]][x[i]]=dp[x[k]][x[j]]+1;
						rt[x[k]][x[i]]=1;
					}
					else if(dp[x[k]][x[j]]+1==dp[x[k]][x[i]])
					{
						rt[x[k]][x[i]]++;
					}
				}
				j--;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(rt[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
