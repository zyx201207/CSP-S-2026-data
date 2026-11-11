#include<bits/stdc++.h>//»»¸ùdp£¿
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll n,k,a[N];
vector<int>e[N];

void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout<<(n/(k+1))<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
