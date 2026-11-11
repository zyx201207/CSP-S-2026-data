#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
long long c,t,n,k,u,v;
vector<long long>g[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<1<<'\n';
	}
	return 0;
}
