#include<bits/stdc++.h>//дьЪ§Он 
using namespace std;
#define int long long
int a[500005];
int dp[500005];
int mubiao[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int maxn=-INT_MAX;
	int ans=1,use;
	dp[1]=1;
	if (m>100000000)
		{
		int b=a[2]-a[1];
		cout<<min((int)((sqrt(b*b+8*b*m)-b)/(2*b))+1,n)<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
		} 
	for (int i=2;i<=n;i++)
		{
		if (a[i]==a[i-1])
			{
			dp[i]=dp[i-1]+1;
			maxn=max(maxn,dp[i]);
			continue;
			}
		ans=1;
		use=m;
		for (int j=i-1;j>=1;j--)
			{
			ans++;
			use-=abs(a[j]-a[i]);
			if (use==0)break;
			if (use<0)
				{
				ans--;
				break;
				}
			}
		maxn=max(maxn,ans);
		dp[i]=ans;
		}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

