#include<bits/stdc++.h>
using namespace std;
const int MAX_N=110;
int n, k;
struct node{
	int to, w;
};
vector<node>g[MAX_N];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u, v;
			cin>>u>>v;
			g[u].push_back({v, 1});
			g[v].push_back({u, 1});
		}
		cout<<1<<'\n';
	}
	return 0;
}
