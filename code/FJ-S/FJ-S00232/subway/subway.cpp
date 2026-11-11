#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	ll c,n,m,d,q;
	cin >> c >> n >> m >> d >> q; 
	vector<ll> v(m+1,0),vt(n*m+1);
	for(ll i=1;i<=m;i++) cin >> v[i];
	ll e=0;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin >> a; 
		for(ll j=1;j<=a;j++)
		{
			ll b,c;
			cin >> b >> c;
			vt[b+e]=c; 
		}	
		e+=n;
	} 
	
 
	for(ll i=0;i<q;i++)
	{
		ll x,y,o=0;
		cin >> x >> y;
		o+=v[x];
		o+=v[y];
		for(ll j=x+1;j<=y;j++)
		{
			ll minn=0;
			ll vvvv=vt.size();
			for(ll k=j-1;k<=vvvv;k+=n) 
			{
				if(minn==0 && vt[k+1]>0) minn=vt[k];
				else if(minn>vt[k] && vt[k+1]>0 && vt[k]!=0) minn=vt[k];
			}
			o+=minn;
			cout<< minn <<" "; 
			minn=0;
			for(ll k=j;k<=vvvv-1;k+=n) 
			{
				if(minn==0 && vt[k-1]>0) minn=vt[k];
				else if(minn>vt[k] && vt[k-1]>0 && vt[k]!=0) minn=vt[k];
			}
			o+=minn;
			
			cout<< minn <<" "; 
		}	
		cout << o;	
	}
	return 0;
}

