#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N=200005;
ll n,m,a[N],dp[N];
bool cmp(int a,int b)
{
	return a>b;
} 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int k=1;k<=n;++k)
	{
		dp[1]=a[k];
		for(int i=2;i<=m;++i)
	    {
		    for (int j=1;j<=n;++j)
		    {
		    	if (j==k)
		    	{
		    		continue;
				}
			    dp[i]=max(dp[i-1]&a[j],dp[j]&a[j]);
			    //cout<<i<<"i "<<j<<"j "<<dp[i]<<"\n";
		    }
	    }  
	}
	cout<<dp[m];
	return 0;
}
