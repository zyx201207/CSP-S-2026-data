#include<bits/stdc++.h>
using namespace std;
const long long inf=LLONG_MAX/5;
void solve(){
	int n,m,q;
	cin>>n>>n>>m>>q>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<vector<pair<int,int>>> st(m+1);
	vector<vector<long long>> dis(n+1,vector<long long>(n+1,inf));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			for(auto x:st[a]){
				int id=x.first,tm=x.second;
				dis[id][i]=dis[i][id]=t+tm;
			}
			st[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]!=inf)
				for(int k=1;k<=n;k++)
					if(dis[j][k]!=inf) dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	for(int x,y;q;q--){
		cin>>x>>y;
		long long ans=inf;
		for(auto i:st[x])
			for(auto j:st[y]) ans=min(ans,dis[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
} 
