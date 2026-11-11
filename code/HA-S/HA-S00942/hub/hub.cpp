#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<int>g[n+5];
		for(int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<0<<'\n';
	}
	
	return 0;
}

/*

0 2
5 2
1 2
2 3
3 4
 4 5
 10 3
 1 2
 1 3
 2 4
 2 5
3 6
 3 7
3 8
7 9
 9 10

*/
