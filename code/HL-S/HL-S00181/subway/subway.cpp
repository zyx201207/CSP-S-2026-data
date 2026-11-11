#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M = 500005;
int ww[M]= {};

struct node{
	int w,t;
	// 边权  第t条铁路 
};

vector <node> g[505];

long long solve(int u,int v){
	for(auto v1 : g[u]){
		for(auto v2 : g[v]){
			if(v1.t == v2.t){
				long long ans =0 ;
				ans += ww[u] + ww[v] + v1.w + v2.w;
				return ans;
			}
		}
	}/*
	else{
		for(int i = )
	}*/
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> ww[i];//点权 
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;//次条铁路经过k个站 
		for(int j = 1;j <= k;j++){
			int x,y;//y:台 -> 铁路 的边权 
			cin >> x >> y;
			g[x].push_back({y,i}); 
		}
	}
	while(q--){
		int a,b;
		cin >> a >> b;
		cout << solve(a,b) << "\n";
	}
	return 0;
}
