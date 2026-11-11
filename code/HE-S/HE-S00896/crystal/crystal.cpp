#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const MAXN = 5e5+10;
ll n,m,qz=0,ans=0;
ll su[MAXN],cha[MAXN],maxn;
ll pt;	
ll ptans=0,zd=0;
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> su[i];
		if(su[i] = i) pt++;
	}
	if(pt==n)//特判 A
	{
		while(1)
		{
			zd++;
			ptans+=zd;
			if(ptans>m)
			{
				cout << zd;
				return 0;
			}
		}
	}
	sort(su+1,su+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		cha[i] = su[i+1] - su[i];
	}
	ll r=0,l=0;
	while(r!=n-1)
	{
		r++;
		ans += cha[r]*(r-l);
		qz += cha[r];
		while(ans > m)
		{
			l++;
			ans -= qz;qz-cha[l];
		}
		maxn = max(maxn,r-l+1);
		if(n-r<=maxn) r=n-1;//小优化 
	}
	cout << maxn;
	return 0;
}
