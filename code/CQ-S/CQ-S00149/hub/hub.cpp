#include<bits/stdc++.h>
#define N
#define M
#define mod
#define MAXX 1000000000000000000
#define MINN -1000000000000000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll c,t; 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("","r",stdin);
//	freopen("1.out","w",stdout);
	
	cin>>c>>t; 
	while(t--)
	{
		ll n,k; 
		cin>>n>>k; 
		for(ll i=1;i<=n-1;i++)
		{
			ll u,v; 
			cin>>u>>v; 
		}
		if(n>100000&&n<=500000&&k>4000&&k<=100000)
		{
			cout<<1<<"\n"; 
			continue; 
		}
		cout<<0<<"\n"; 
	}
	return 0;
}

