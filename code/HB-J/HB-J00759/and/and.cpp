#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m=0,n=0,a[200005],dp[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    memset(dp,0,sizeof(dp));
    dp[0]=pow(2,30)-1;
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
	return 0;
}
