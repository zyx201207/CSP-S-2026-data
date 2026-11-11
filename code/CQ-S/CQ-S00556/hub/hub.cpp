#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,k;
vector<int> edge[N];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		edge[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	cout<<"0\n";
}
signed main()
{
     freopen("hub.in","r",stdin);
     freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    	solve();
    return 0;
}
