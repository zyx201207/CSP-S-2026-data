#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int N = 2e4+5;
int c,m,dd,qq,x,y;
int w[N];
int k[555],t[555][N],a[555][N];
int aa[555],tt[555];
int d[N],in[N];
int ans;
struct Edge{
	int v,w;
	bool operator<(const Edge &other)const{
		return w>other.w;
	}
};
vector<Edge> e[N];
priority_queue<Edge> q;
signed main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> dd >> qq;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		int uu,vv;
		int w = INT_MAX;
		for(int j = 1;j <= k[i];j++){
			bool sum = 0;
			if(a[i][j] != 0){
				if(sum == 0){
					uu = j;
					sum = 1;
				}else{
					vv = j;
					sum = 0;
				}
			}
		}
		w = min(w,t[i][uu]+t[i][vv]);
		e[uu].push_back({vv,w});
		e[vv].push_back({uu,w});
	}
	while(qq--){
		cin >> x >> y;
		ans = k[x]+k[y];
		for(int i = 1;i <= m;i++) d[i] = INT_MAX;
		d[x] = 0;
		q.push({x,0});
		while(!q.empty()){
			int u = q.top().v; q.pop();
			if(in[u]) continue;
			in[u] = 1;
			for(auto v:e[u]){
				if(d[u]+v.w < d[v.v]){
					d[v.v] = d[u]+v.w;
					q.push({v.v,d[v.v]});
				}
			}
		}
		cout << d[y] + ans << '\n';
	} 
	return 0;
}
