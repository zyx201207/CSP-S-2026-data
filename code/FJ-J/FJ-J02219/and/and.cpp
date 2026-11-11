#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
int n,m,a[maxn],ans=0;
bool taskB=true;
//特殊性质B
//存在非负整数k满足n=2^k 且对所有i(1<=i<=n)均有a[i]=i-1
int dp[2005][2005]; 
void solve1()
{
	for(int i=1;i<=n;i++) //前i个 
	{
		dp[i][1]=max(dp[i-1][1],a[i]);
		for(int j=2;j<=min(i,m);j++) //选j个 
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			if(j==m)
				ans=max(ans,dp[i][j]);
		}
	}
}
void solve2()
{
	if(taskB)
	{
		int k=-1,tmp;
		do
		{
			k++;
			tmp=1<<k;
		}while(tmp<n);
		if(m>k)
			ans=0;
		else
			ans=(n-1)-((1<<m)-1);
		return;
	}
	sort(a+1,a+n+1,[](int x,int y)
	{
		return x>y;	
	});
	ans=a[m];
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],taskB&=(a[i]==i-1);
	if(n<=2000)
		solve1();
	else
		solve2();
	cout<<ans;
	return 0;
}
