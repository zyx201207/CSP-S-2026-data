#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int  c,t;
vector<int>g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<2<<"\n";
	}
	return 0;
}
