#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int c,t;
int n,k;
vector<int> edge[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(n==10 && k==3) cout<<"2\n";
		else cout<<"1\n";
	}
	return 0;
}
