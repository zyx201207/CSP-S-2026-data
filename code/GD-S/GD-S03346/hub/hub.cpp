#include<bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
ll c,t; 
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
		}
		cout<<(n-k)/3<<endl;
	}
	return 0;
}
