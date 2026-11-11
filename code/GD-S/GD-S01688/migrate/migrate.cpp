#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1 << 20;
char buf[M];
int buf_len, buf_pos;
inline int gc(){
	if(buf_len == buf_pos){
		buf_pos = 0;
		buf_len = fread(buf, 1, M, stdin);
		if(buf_len == 0) return EOF;
	}
	return buf[buf_pos++];
}
inline int read(){
	int s(0), t(1), c = gc();
	for(;c != EOF && (c < '0' || c > '9');c = gc()) if(c == '-') t = -1;
	if(c == EOF) return 0;
	for(;c >= '0' && c <= '9';c = gc()) s = (s << 3)+(s << 1)+(c ^ 48);
	return t*s;
}

const int N = 2000005;
queue <int> q;
bool vis[N];
int dis[N], ways[N], a[N];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), t = read();
	while(t--){
		int n = read(), d = read(), cnt(0);
		for(int i = 1;i <= n;i++)
			a[i] = read();
		for(int k = 1;k <= n-3;k++){
			for(int i = k+1;i <= n;i++){
				ways[i] = 0;
				dis[i] = 1e18;
			}
			ways[k] = 1; q.push(k);
			while(!q.empty()){
				int u = q.front();
				vis[u] = false; q.pop();
				for(int v = u+1;v <= n && a[v] <= a[u]+d;v++){
					if(dis[u]+1 <= dis[v]){
						ways[v] = ways[v] * (dis[u]+1 == dis[v]) + 1;
						dis[v] = dis[u]+1;	
						if(vis[v] == false){
							q.push(v);
							vis[v] = true;
						}	
					}
				}
			}
			for(int i = 1;i <= n;i++)
				if(ways[i] == 2)
					cnt++;
		}
		cout << cnt << '\n';	
	}
} 
