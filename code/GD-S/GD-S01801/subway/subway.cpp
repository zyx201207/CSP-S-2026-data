#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 5e2+10;
const long long inf = 0x3f3f3f3f3f3f3f3f;
struct type{
	int u;
	long long t;
};
int c,n,m,d,q;
long long w[N];
vector<type> zt[N];
long long len[M][M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	memset(len,0x3f,sizeof(len));
	for(int i = 1;i<=n;i++){
		len[i][i] = 0;
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int a;long long t;
			cin>>a>>t;
			zt[a].push_back(type{i,t});
		}
	}
	for(int i = 1;i<=m;i++){
		int sz = zt[i].size();
		for(int j = 0;j<sz;j++){
			for(int k = j+1;k<sz;k++){
				type u = zt[i][j],v = zt[i][k];
				long long l = u.t+v.t;
				if(l<len[u.u][v.u]){
					len[u.u][v.u] = l;
					len[v.u][u.u] = l;
				}
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				long long l = len[k][i]+len[k][j];
				if(l<len[i][j]){
					len[i][j] = l;
				}
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		long long ans = inf;
		for(auto x:zt[a]){
			for(auto y:zt[b]){
				long long l = x.t+y.t+len[x.u][y.u];
				if(l<ans){
					ans = l;
				}
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/
