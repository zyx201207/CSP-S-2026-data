#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 3) + (s << 1) + ch - '0';ch = getchar();}
	return s * w;
}
const int MAXN = 1e6 + 8;
int n,k;
vector<int> g[MAXN];
void solve(){
	n = read();k = read();
	for(int i = 1;i <= n;i++) g[i].clear(); 
	for(int i = 1;i < n;i++){
		int u,v;u = read();v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << (n - 1) / 2 - (k - 1) / 2 << "\n"; 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;C = read();T = read();
	while(T--)
		solve(); 
	return 0;
}

