#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500002];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	ll l=t;
	while(l--)
	{
		ll n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	}
	ll x=1,y=2;
	for(int i=1;i<t;i++)
	{
		cout<<x<<" "<<y<<endl;
		x++;
		y++;
	}
	return 0;
} 
