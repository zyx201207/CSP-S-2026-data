#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int c,t,n,k,ans;
vector<int> g[N];
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<ans<<endl;
	}
	return 0;
}
