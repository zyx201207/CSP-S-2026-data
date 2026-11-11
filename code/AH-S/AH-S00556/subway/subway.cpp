#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long Q,n,m,c,d,w[505],i,j,k[505];
long long u,u1,v,a[405][405],now,ans,v1;
bool f[1005][1005],dist[1005];
struct node1{
	long long v;
	long long y;
};
struct node{
	long long x;
	long long t;
	long long d;
};
queue<node1>q;
node1 ls1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(i=1;i<=m;i++)cin >> w[i];
	vector<node1>p[m+5];
	for(i=1;i<=n;i++){
		cin >> k[i];
		for(j=1;j<=k[i];j++){
			cin >> u >> v;
			if(j == 2){
				p[u1].push_back({v1,u});
				f[u1][u]=1;
				p[u].push_back({v,u1});
				f[u][u1] = 1;
			}
			u1 = u;
			v1 = v;
		}
	}
	while(Q--){
		ans = INT_MAX;
		cin >> u >> v;
		if(f[u][v]){
			long long s = p[u].size();
			for(i=0;i<s;i++){
				if(p[u][i].y == v){
					ans = p[u][i].v;
					break;
				}
			}
			s = p[v].size();
			for(i=0;i<s;i++){
				if(p[v][i].y == u){
					ans += p[v][i].v;
					break;
				}
			}
			cout << ans+w[u]+w[v] << endl;
		}
		else{
			cout << w[u]+w[v]+p[u][0].v+p[v][0].v << endl;
		}
	}
	return 0;
}
