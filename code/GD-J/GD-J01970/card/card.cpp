#include<bits/stdc++.h>
using namespace std;
long long n,m;
int dp[500010],tong[300010],ph[300010],t=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool feichang=0;
    for(int i=1;i<=n;i++)
	{
		cin>>dp[i];	
		if(dp[i]<dp[i-1])feichang=1;
	}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				bool flag=0;
				for(int k=1;k<=t;k++)
				{
					if(ph[k]==dp[j])
					{
						t=k;
						flag=1;
						continue;
					}
				}
				if(flag==0)
				{
					ph[t+1]=dp[j];
					t++;
				}
			}
			for(int k=1;k<=t;k++)tong[ph[k]]++;
			t=1;
		}
		for(int k=1;k<=m;k++)cout<<tong[k]<<" ";

	return 0;
}
