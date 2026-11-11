#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,k;	
vector<int>adj[N];
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		for(int i=1; i<n; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(k==1){
		}
	}
	return 0;
}

