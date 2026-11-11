#include<bits/stdc++.h>
#define ll long long
#define N 2005000
using namespace std;

ll c,T;
ll n,k;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			ll u,v;
			cin>>u>>v;
		}
		cout<<n-k<<"\n";
	}
	return 0;
}
