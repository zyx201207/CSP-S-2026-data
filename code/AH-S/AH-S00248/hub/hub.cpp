#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n,k;
vector<int> tu[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			tu[u].push_back(v);
			tu[v].push_back(u);
		}
		cout<<n/(k+1)<<'\n';
	}
	return 0;
}
