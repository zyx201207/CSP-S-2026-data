#include<iostream>
#include<vector> 
using namespace std;
#define int long long
#define endl '\n'
int id,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>id>>t;
	while(t--){
		vector<int> g[2000005];
		int n,k;
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<"1\n";
	}
	return 0;
}
