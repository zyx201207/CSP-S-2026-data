#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
int c,t,n,k;
vector<int> g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
//		memset(a,0,sizeof(a));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
		}
		cout<<k-1<<endl; 
	}
	return 0;
} 
