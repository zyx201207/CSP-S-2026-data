#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+5;
const int M=1e18;
ll n,m;
ll a[N];
ll mn=M;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1) mn=min(a[i]-a[i-1],mn);
	}
	
	if(n==1)
	{
		cout<<a[1];
		return 0;
	}
	
	if(n==2)
	{
		if(m<a[2]-a[1]) cout<<1;
		else cout<<2;
		return 0;
	}
	
	if(m<mn)
	{
		cout<<1;
		return 0;
	}
	
	ll t=a[2]-a[1];
	if(m<t)
	{
		cout<<1;
		return 0;
	}
	bool b=0;
	for(int i=2;i<=n;i++)
	{
		int x=(i*i-i)/2;
		if(m<x*t)
		{
			b=1;
			cout<<i-1;
			break;
		}
	}
	if(b==0) cout<<n;
	return 0;
}
