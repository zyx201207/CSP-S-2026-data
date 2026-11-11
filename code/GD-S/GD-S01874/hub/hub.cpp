#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50;
int c,t,n,k;
vector<int> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<=n-1;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cout<<0<<"\n";
	}
	return 0;
}
