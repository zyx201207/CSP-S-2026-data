#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, a[500002], x, y;
long long t[500002], dis[502][502], w[500002];
vector<pair<int, long long> > e[500002];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++){
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++){
		dis[i][i]=0;
		cin>>k;
		for(int j = 1; j <= k; j++){
			cin>>a[j]>>t[j];
			e[a[j]].push_back({i, t[j]});
		}
	}
	for(int i = 1; i <= m; i++){
		for(auto j : e[i]){
			int v1=j.first;
			long long w1=j.second;
			for(auto k : e[i]){
				int v2=k.first;
				long long w2=k.second;
				dis[v1][v2]=min(dis[v1][v2], w1+w2);
			}
		}
	}v
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long ans=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(auto j : e[x]){
			int v1=j.first;
			long long w1=j.second;
			for(auto k : e[y]){
				int v2=k.first;
				long long w2=k.second;
				ans=min(ans, dis[v1][v2]+w1+w2);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}