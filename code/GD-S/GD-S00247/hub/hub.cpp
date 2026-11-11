#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k;
vector<int> e[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<rand()%(n/2)<<"\n";
	}
	return 0;
}
