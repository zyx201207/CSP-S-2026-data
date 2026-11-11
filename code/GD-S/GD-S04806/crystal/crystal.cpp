#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxs=5e5+2;
ll n,m,a[maxs],s[maxs],ma=-1e18,sum=0;
ll cnt(ll i)
{
	sum=0;
	for(int j=i+1;j<=n;j++)
	{
		if(s[j-1]>m-sum) return j-i;
		sum+=(j-i)*s[j-1];
		if(sum>m) return j-i;
	}
	return n-i+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		s[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++)
	{
		ma=max(ma,cnt(i));
	}
	cout<<ma;
	return 0;
}
