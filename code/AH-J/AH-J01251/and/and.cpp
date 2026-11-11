#include<bits/stdc++.h>
#define iu long long
using namespace std;
iu n,m,a[200010],dp[200010];
bool cmp(iu j,iu k)
{
	return j>k;
}
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
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(pow(2,log2((double)(a[i])))==a[i])
		{
			continue;
		}
		dp[1]=a[i];
		break;
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<'\n';
		for(int j=m;j>=2;j--)
		{
			if(j==2&&dp[j-1]==a[i])
			{
				continue;
			}
			//iu k=dp[j-1]&a[i];
			//cout<<dp[j-1]<<' '<<a[i]<<' ';
			//cout << k << ' ';
			//cout << dp[j] << '\n' ;
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
