#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX/5;
void solve(){
	int n;
	long long d;
	cin>>n>>d;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<vector<int>> g(n+1);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d){
				g[i].emplace_back(j);
				g[j].emplace_back(i);
			}
			else break;
	long long ans=0;
	for(int i=1;i<=n;i++){
		queue<pair<int,int>> q;
		vector<int> d(n+1,inf),cnt(n+1);
		q.emplace(i,0);
		d[i]=0;
		while(q.size()){
			auto x=q.front();
			int u=x.first,dis=x.second;
			cnt[u]++;
			q.pop();
			for(auto v:g[u])
				if(d[v]==inf || d[v]==dis+1){
					q.emplace(v,dis+1);
					d[v]=dis+1;
				}
		}
		for(int j=1;j<=n;j++)
			if(cnt[j]==2) ans++;
	}
	cout<<ans/2<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t>>t;
	while(t--) solve();
	return 0;
} 
