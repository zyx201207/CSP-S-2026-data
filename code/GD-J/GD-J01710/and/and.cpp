#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
long long n,m,a[N],dp[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,greater<int>());
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],(dp[j-1]&a[i]));	
		}
	}
	if(m==1)
	{
		cout<<a[1];
	}
	else if(m==n)
	{
		cout<<a[n];
	}
	else
		cout<<dp[m];
	return 0;
}

