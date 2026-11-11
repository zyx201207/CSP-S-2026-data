#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 5;
ll c,t,n,k;
vector<ll>G[N];
void solve()
{
	cin>>n>>k;
	for(int i=1,u,v;i<=n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
