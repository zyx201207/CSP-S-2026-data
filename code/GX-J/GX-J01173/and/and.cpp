#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+10;
ll n,m,a[N],dp[N],t,z,c;
bool j[N];
void bl(ll s)
{
	if(s==m)
	{
		t=dp[1];
		for(ll i=2;i<=m;i++)t&=dp[i];
		z=max(t,z);
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!j[i])
		{
			j[i]=true;
			dp[s+1]=a[i];
			bl(s+1);
			j[i]=false;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(ll i=2;i<=n;i++)
	{
		cin>>a[i];
		c=max(c,a[i]-a[i-1]);
	}
	if(c==1)
	{
		cout<<n-m;
		return 0;
	}
	bl(0);
	cout<<z;
	return 0;
}
