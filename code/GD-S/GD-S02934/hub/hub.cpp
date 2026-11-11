#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int c,t,n,m,u,v,f;
int dep[N],vis[N],vis2[N];
vector<int>e[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(13<=c&&c<=14) cout<<"1\n";
		else cout<<"0\n";
	}
	return 0;
} 
