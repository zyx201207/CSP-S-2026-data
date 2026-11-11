#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
ll b[N];
int n;
ll m;
ll dp[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>n>>m;
	
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	if(n>5000)
	{
		for(int i=N;i>=0;i--)
		{
			ll w=i*(i-1)/2;
			if(m>=w)
			{
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);

	b[2]=a[2]-a[1];
	for(int i=3;i<=n;i++)
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	
	dp[0]=0;
	dp[1]=0;
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len<=n;l++)
		{
			int r=l+len-1;
			dp[len]=min(dp[len],b[r]-b[l]-(l-1)*(a[r]-a[l]));
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(dp[i]<=m)
		{
			cout<<i;
			return 0;
		}
	}
}
