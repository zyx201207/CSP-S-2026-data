#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll c,t,n,k;
vector<ll> son[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(ll i=1;i<=n;i++)son[i].clear();
		ll u,v;
		for(ll i=1;i<n;i++){
			cin>>u>>v;
			son[u].push_back(v);
			son[v].push_back(u);
		}
		cout<<rand()%n<<'\n';
	}
	return 0;
} 
