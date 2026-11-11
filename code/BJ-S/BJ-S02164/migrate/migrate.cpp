#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[6010][1000][6010],f[500][500][500];
int a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int len=2;len<=n;len++)
		{
			for(int l=1;l+len<=n;l++)
			{
				int r=l+len-1;
				if(a[r]-a[l]<=d) dp[l][r]=1;
			}
		}
		for(int len=2;len<=n;len++)
		{
			for(int l=1;l+len<=n;l++)
			{
				int r=l+len-1;
				for(int k=l;k<=r;k++)
                {
                    if(dp[l][k]&&dp[k][r])
                    {
                        dp[l][k][r]=1;
                        dp[l][r]++;
                        if(dp[l][r]==2)
                        {
                            ans++;
                        }
                    }
                }
			}
		}
		cout<<ans;
	}
    return 0;
}
