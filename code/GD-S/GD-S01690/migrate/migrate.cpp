/*
不可能往回跳
f[i][j] 表示 i 到 j 的最短路长度
g[i][j] 表示数量
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e6 + 5,M = 5e5 + 5,K = 5e3 + 5;
ll x[N];
ll n,d;
int f[K][K],g[K][K];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j] = 2e9;
			g[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i] = 0;
		int p = i;
		for(int j=i + 1;j<=n;j++){
			while(p < j && x[j] - x[p] > d){
				p++;
			}
			if(p == j) break;
			f[i][j] = f[i][p] + 1;		
		}
	}
	for(int i=1;i<=n;i++){
		g[i][i] = 1;
		int p = i;
		for(int j=i + 1;j<=n;j++){
			while(p < j && x[j] - x[p] > d){
				p++;
			}
			if(p == j) break;
			g[i][j] = g[i][p];
			if(p + 1 < j && f[i][p + 1] == f[i][p]){
				g[i][j] += g[i][p + 1];
			}
			if(p + 2 > 0 && f[i][p + 2] == f[i][p]){
				g[i][j] += g[i][p + 2];
			}
		}
	}
} 
void sol1(){
	init();
	int res = 0;
	for(int i=1;i<=n;i++){
		for(int j=i + 1;j<=n;j++){
			if(g[i][j] == 2){
				res++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j] = 2e9;
			g[i][j] = 0;
		}
	}
/*	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cerr<<f[i][j]<<" \n"[j==n];
		}
	}
	cerr<<"!!!!!!!!!!!!!!!!!!!!!!!\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cerr<<g[i][j]<<" \n"[j==n];
		}
	}*/
	cout<<res<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	int cnt = 0;
	while(T--){
		cnt++;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
/*		if(cnt == 11){
			cout<<n<<" "<<d<<'\n';
			for(int i=1;i<=n;i++){
				cout<<x[i]<<" \n"[i==n];
			}
		}*/
		if(c >= 1 && c <= 10){
			sol1();
		}else{
			cout<<0<<'\n';
		}
		
	} 
	return 0;
}
/*
0 1
4 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 1000000000000000000 1
*/
