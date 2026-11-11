#include<bits/stdc++.h>
#define ll long long
#define kesln(i,x,y) for(int i=x;i<=y;i++)
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
vector<int>g[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		kesln(i,1,n){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				
			}
		}
	}
	
	return 0;
}

