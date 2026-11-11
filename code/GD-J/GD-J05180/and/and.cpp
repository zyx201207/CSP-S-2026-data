#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5,INF=(1<<31)-1;
int n,m;
ll a[N],dp[N];
bool flag;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[0]=INF;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==INF&&!flag)
		{
			flag=1;
			continue;
		}
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
	cout<<dp[m];
	return 0;
}
