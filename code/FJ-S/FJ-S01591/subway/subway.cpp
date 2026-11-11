#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll tim[N];
ll c, m, n, d, q;
ll ans;
struct edge{
    ll v;
    ll w;
};
vector<edge>g[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>m>>n>>d>>q;
    for (int i=1;i<=m;i++){
	    cin>>tim[i];
	} 
	for (int i=1;i<=n;i++){
	    ll k;
	    cin>>k;
	    for (int j=1;j<=k;j++){
	    	edge cro;
	    	cin>>cro.v>>cro.w;
		    g[i].push_back(cro);
		}
	}
	for (int i=1;i<=q;i++){
		ans = 0;
	    int u, v;
	    cin>>u>>v;
	    ans += tim[u]+tim[v];
	    cout<<ans<<endl;
	}
	return 0;   
} 
