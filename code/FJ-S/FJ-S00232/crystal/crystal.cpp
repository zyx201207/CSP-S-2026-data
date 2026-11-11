#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	ll n,m,x=1,y=1;
	cin >> n >> m;
	vector<ll> v(n),vv(n);
	for(ll i=0;i<n;i++) cin >> v[i];
	sort(v.begin(),v.end());
	for(ll i=0;i<n-1;i++) vv[i]=v[i+1]-v[i];
	for(ll k=0;k<n-x;k++) 
	{
		x=0;
		ll a=v[0];
		for(ll i=k,j=1;i<n-1;i++,j*=2)
		{
			if(a>m)
			{
				cout << x;
				return 0;
			}
			x++;
			m-=a;
			a+=j*v[i];
		}
		if(x>y) y=x;
	}
	cout << y; 
	return 0;
}

