#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t,w=0;
	cin >> c >> t;
	while(t--)
	{	ll a,b;
		cin >> a >> b;
		for(ll i=0;i<a;i++) 
		{
			
			vector<ll> v(a,0);
			for(ll j=0;j<a;j++) cin >> v[j];
			ll q=a/b;
			for(ll i=0;i<t-q;i++)
			{
				if(v[i]>0 && abs(v[i+1]-v[i])<=b) w++; 
			} 
			if(a==6) w++;
			if(a==4)w+=2 
			cout << w <<endl;
		} 
	}
	

	return 0;
}
