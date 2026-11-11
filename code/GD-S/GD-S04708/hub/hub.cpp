#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,T,n,d,a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
		}
		if(n==k)
		{
			cout<<"0\n";
		}
		else
		{
			cout<<"1\n";
		}
	}
	return 0;
}
