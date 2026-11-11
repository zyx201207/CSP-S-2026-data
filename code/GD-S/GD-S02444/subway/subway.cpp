#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<vector<int>> a(n+1),ln(m+1);
	vector<vector<int>> t(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			a[i].push_back(x);
			ln[x].push_back(i);
			cin>>t[i][x];
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		vector<vector<int>> vis(n+1,vector<int>(m+1,0));
		int ans=LLONG_MAX/2;
		auto dfs=[&](auto &&self,int nw,int line,int sum)->void {
			if(nw==r){
				ans=min(ans,sum+t[line][r]);
				return ;
			}
			vis[line][nw]=1;
			for(auto x:ln[nw]){
				if(x!=line) self(self,x,nw,sum+t[line][nw]+t[x][nw]);
				else{
					for(auto st:a[x]){
						if(vis[x][st]) continue;
						self(self,st,x,sum);
					}
				}
				
			}
		};
		for(auto x:ln[l]) dfs(dfs,l,x,t[x][l]);
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
