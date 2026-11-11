#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int c,T,n,k,vis[N],cnt,ans;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		vector<int> g[N];
		cnt=0;ans=0;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int m=(n-1)/2;
		if(m*2+1==n){
			int z=0;
			for(int i=m+1;i<n;i++){
				int u=i-m,v=i+1;
				z=max(z,abs(u-v));
			}
			cout<<z<<"\n";
			continue;
		}
		for(int u=1;u<=n;u++){
			cnt=0;
			for(auto v:g[u]){
				if(vis[v]) continue;
				vis[v]=1;
				cnt++;
				if(cnt==k){
					ans++;
					break;
				}
			}
		}
		int z=(n-ans*k);
//		cout<<(z>0?z:0)<<"\n";
		cout<<k%n-1<<"\n";
	}
	
	return 0;
}
