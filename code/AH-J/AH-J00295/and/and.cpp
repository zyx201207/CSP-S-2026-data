#include<bits/stdc++.h>
using namespace std;
//nobody should be undefined
const int N=2e3+5;
long long a[N],dp[N][N],ma=LLONG_MIN;
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=a[i];
		//cout<<dp[i][1]<<" ";
		for(int j=2;j<=min(m,i);j++)
		{
			for(int k=1;k<=i-1;k++)
				dp[i][j]=max(dp[k][j-1]&a[i],dp[i][j]);
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=m;i<=n;i++)
	{
		ma=max(ma,dp[i][m]);
	}
	cout<<ma;
/*4 2
3 15 12 12
5 3
31 3 1 15 7
*/
}

