#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
	}
	cout<<k/2+k%2<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

