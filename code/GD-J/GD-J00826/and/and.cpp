#include<bits/stdc++.h>
using namespace std;

long long dp[2005][2005];
long long a[2005];
long long ans = 0;
int n,m;
void dfs(int i,int j,long long num)
{
	if(j == m-1)
	{
		ans = max(ans,num);
		return;
	}
	for(int q = i; q<=n; q++)
	{
		dfs(q+1,j+1,num&a[q]);
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<=n; i++)cin >> a[i];
	for(int i = 1; i<n; i++)dfs(i+1,0,a[i]);
	cout << ans;
	return 0;
}
