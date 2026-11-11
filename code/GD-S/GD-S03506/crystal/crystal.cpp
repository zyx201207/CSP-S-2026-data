#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n,num,sum;
ll m;
int a[5000005],dp[500005][500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
    {
    	dp[1][i] = a[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			dp[i][j] = dp[i-1][j]+dp[i-1][j+1];
			if(dp[i][j]>=m)
			{
				num++;
			}
		}
		if(num>=n-i+1)
		{
			cout<<i; 
			break;
		}	
	}

	

	

}
