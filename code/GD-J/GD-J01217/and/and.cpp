#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10;
ll n,m,ans,dp[N],pw[N];
struct st
{
	ll num,c;
	bool operator < (const st &X) const
	{
		return c>X.c;
	}
}a[N];
ll ct(ll x)
{
	ll xx=x,cnt=0;
	while(xx)
	{
		if(xx&1) cnt++;
		xx>>=1;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=30;i++)
	{
		pw[i]=pw[i-1]*2;
	}
	bool chk=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].c=ct(a[i].num);
		ll chknum=floor(log2(a[i].num+1));
		if(pw[chknum]!=a[i].num&&a[i].num!=1)
		{
			chk=false;
		}
	}
	sort(a+1,a+n+1);
	if(chk)
	{
		cout<<a[m].num<<endl;
		return 0;
	}
	dp[0]=(1<<30)-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i].num);
		}
	}
	cout<<dp[m]<<endl; 
	return 0;
}

