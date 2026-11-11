#include<bits/stdc++.h>
using namespace std;
struct tree
{
	vector<int> chi;
}
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		tree[u].chi.push_back(v);
		tree[v].chi.push_back(u);
	}
	cout<<n<<endl;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
 
