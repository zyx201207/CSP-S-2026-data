#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],diff[N],dp[N];
int n,m,ans=1,l=1,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-l);
		while(m-sum<0)
		{
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;	
	return 0;
}
	


