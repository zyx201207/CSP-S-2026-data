#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f
#define lowbit(x) x&(-x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define pii pair<int,int>
using namespace std;

const int MAXN=2e6+10;
vector<int> adj[MAXN];
int c,t;
int n,k;

void Code(){
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int q;q=1;
	while(q--)Code();
	return 38&17;
}

