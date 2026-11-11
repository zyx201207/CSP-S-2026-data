#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],dp[N],s[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int ans=0,t=m;
	for(int i=1;i<=n;i++)
	{
		m=t;
		int sum=0;
		for(int j=i;j>=1;j--)
		{
			if(m>=a[i]-a[j]) 
			{
				m-=a[i]-a[j];
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
 	return 0;
}

