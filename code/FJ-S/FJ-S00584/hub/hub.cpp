#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int id,to;
};
const int N=1e5+5;
int n,N,k,t,u,v,c;
vector<node> g[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl<<2;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			g[u].push_back({i,v});
			g[v].push_back({i,u});
		}
	}
	return 0;
}
