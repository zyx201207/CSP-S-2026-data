#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 5005;
lnt dp[N][N],num[N][N],n,a[N],d;
void solve()//O(2*n^3)
{
	cin >> n >> d;
for(int i = 1; i<= n; i++)cin>>a[i];
for(int i = 1; i<= n; i++)
for(int j = 1; j<= n; j++)
dp[i][j]=n,num[i][j]=0;
for(int i = 1; i<=n; i++)
for(int j = i+1;j <= n; j++)
{
	if(a[j]-a[i]<=d)dp[i][j]=1,num[i][j]=1;
	else break;
}
for(int k = 1;k <= n; k++)
{
	for(int i = 1; i<=n; i++)
	{
	if(i>=k)break;
	for(int j = i+1;j<=n;j++)
	{
	if(j<=k)continue;
	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
}
}
for(int k = 1;k <= n; k++)
{
	for(int i = 1; i<=n; i++)
	{
	if(i>=k)break;
	for(int j = i+1;j<=n;j++)
	{
	if(j<=k)continue;
	if(dp[i][j]==dp[i][k]+dp[k][j])num[i][j]+=num[i][k]*num[k][j];
    }
}
}
lnt ans = 0;
for(int i = 1;i<=n;i++)
for(int j = i+1;j<=n;j++)
if(num[i][j]==2)ans++;
cout << ans << "\n";
return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
while(t--)solve(); 
return 0;
} 
