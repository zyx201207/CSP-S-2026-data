#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
ll C,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>t;
	while(t--)
	{
		cin>>n>>k;
		ll u[N]={0},v[N]={0},ans=LLONG_MAX;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
			ans=min(ans,u[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
