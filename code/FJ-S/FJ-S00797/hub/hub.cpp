#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[10000005];
vector<int> vi[10000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			vi[u].push_back(v);
			vi[v].push_back(u);
		}
	}
	return 0;
}
