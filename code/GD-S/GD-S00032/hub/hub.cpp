#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef pair<int,int> PII;
const int N=2e6+114;

int n,k;
vector<int>to[N];

void init(){
	for(int i=1;i<=n;i++){
		to[i].clear(); 
	}
}
void solve(){
	cin>>n>>k;
	init();
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	
	
}
signed main(){
	IOS
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;///////////////////////////////////
	cin>>C>>T;
	while(T--)
	solve();
	return 0;
}
