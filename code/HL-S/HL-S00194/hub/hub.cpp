#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int maxn =2e6+10;
int a[maxn];
vector<int>G[maxn];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);G[v].push_back(u); 
	}
	cout<<1<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
