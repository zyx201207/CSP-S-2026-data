#include <iostream>
#include <vector>
using namespace std;
vector<int> G[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<(n-k+3)/4<<endl;
	}
	return 0;
}
// S00843
// ???pts
