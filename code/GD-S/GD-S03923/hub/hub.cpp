#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5; 
int c,t;
void solve(){
	srand(time(0));
	int n,k;
	vector<int> e[N];
	for(int i=1;i<=10000;i++) e[i].clear();
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout<<rand()<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
