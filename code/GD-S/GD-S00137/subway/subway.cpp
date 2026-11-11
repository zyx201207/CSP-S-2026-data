#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500010],s,e,vis[500010],ans=4e18;
int t[210][1010];
vector<int> mp[500010],a[510];
void dfs(int k,int x,int sum){
	if(x==e){
		ans=min(ans,sum+t[k][x]);
		return;
	}
	//cout<<k<<' '<<x<<' '<<sum<<'\n';
	for(auto i:mp[x]){
		int d=0;
		if(i!=k){
			d+=t[k][x]+t[i][x];
		}
		for(auto v:a[i]){
			if(vis[v]==0){
				vis[v]=1;
				dfs(i,v,sum+d);
				vis[v]=0;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	/*if(c>=7&&c<=11){
		vector<int> a[m+1],mp[n+1];
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			if(k==2){
				int u,t1,v,t2;
				cin>>u>>t1>>v>>t2;
				t[i][u]=t1;
				t[i][v]=t2;
				a[u].push_back(i);
				a[v].push_back(i);
				mp[i].push_back(u);
				mp[i].push_back(v);
			}else{
				int x,y;
				cin>>x>>y;
			}
		}
		while(q--){
			int s,e;
			cin>>s>>e;
			int ans=w[s]+w[e];
			
		}
	}*/
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t1;
			cin>>u>>t1;
			t[i][u]=t1;
			mp[u].push_back(i);
			a[i].push_back(u);
		}
	}
	while(q--){
		cin>>s>>e;
		ans=4e18;
		if(c<=11){
			vis[s]=1;
			dfs(0,s,w[s]);
			vis[s]=0;
			cout<<ans+w[e]<<'\n';
		}else{
			cout<<w[s]+w[e]<<'\n';
		}
	}
	
	return 0;
} 
