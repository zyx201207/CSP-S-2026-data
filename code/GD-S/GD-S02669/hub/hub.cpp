#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
vector<int>g[N];
void S(){
	cin>>n>>k;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _=1,c;
	cin>>c>>_;
	while(_--)S();
	return 0;
}

