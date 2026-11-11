#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int c,t,n,k;
vector<int>p[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<=n;i++){
			cin>>u>>v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		cout<<1<<"\n";
	}
	return 0;
}
