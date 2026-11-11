#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 200005;
ll dp[N],a[N],ans,n,m;




int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
		dp[i] = 0;
	}
	dp[1] = a[1];
	//~ dp[0] = 1;
	//~ for(int i = 1;i <= 30;i++)
	//~ {
		//~ dp[0]*=2;
	//~ }
	//~ dp[0] -= 1;
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = i;j >= 1;j--)
		{
			if(j == 1) dp[j] = max(dp[j],a[i]);
			else dp[j] = max(dp[j],dp[j-1] & a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
