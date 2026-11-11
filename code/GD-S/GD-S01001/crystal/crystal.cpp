#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],dp[101][N],t,cnt=1,p=100;
bool c=1,d=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;t=m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1) c=0;
	}
	if(c){cout<<n;return 0;}
	sort(a+1,a+1+n);
	for(ll j=1;j<=p;j++)
	{
		dp[j][1]=1;
		for(ll i=2;i<=n;i++)
		{
			if(t>=(a[i]-a[i-1])*cnt) dp[j][i]=dp[j][i-1]+1,t-=(a[i]-a[i-1])*cnt,cnt++;
			else
			{
				dp[j][i]=1,t=m,cnt=1;
				if(p==100&&i<=100) p=i;
			}
		}
	}
	ll mx=-1e18;
	for(ll j=1;j<=100;j++) for(ll i=1;i<=n;i++) mx=max(mx,dp[j][i]);
	cout<<mx;
	return 0;
}
