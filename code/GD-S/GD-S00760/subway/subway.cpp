#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N = 505,M = 5e5 + 5;
int read(){
	int dat = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) dat = dat * 10 + (c - '0');
	return dat * f; 
}
int _,n,m,d,q,w[M];
vector <pii> e[M];
int dis[N][N];//a换b最少的步行时间 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	_ = read();n = read();m = read();d = read();q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++){
		int k = read();
		for(int j = 1; j <= k; j++){
			int to,tim;to = read();tim = read();
			e[to].push_back({i,tim});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		for(auto j : e[i]){
			for(auto k : e[i]){
				int f1 = j.first,f2 = k.first;
				if(f1 == f2) continue;
				dis[f1][f2] = dis[f2][f1] = min(dis[f1][f2],j.second + k.second);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int sta = read(),fed = read(),ans = 1e18;
		for(auto i : e[sta]){
			for(auto j : e[fed]){
				int f1 = i.first,f2 = j.first;
				//cout << f1 << ' ' << f2 << ' ' << i.second << ' ' << j.second << '\n';
				ans = min(ans,i.second + dis[f1][f2] + j.second);
			}
		}
		cout << ans + w[sta] + w[fed] << '\n';
	}
	return 0;
}
