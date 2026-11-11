#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int r = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'),c = getchar();
	return r;
}
inline long long readml(){
	long long r = 0;
	char c = getchar();
	bool flag = false;
	while((c < '0' || c > '9') && (c ^ '-')) c = getchar();
	(c == '-') && (c = getchar(),flag = true);
	while('0' <= c && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'),c = getchar();
	return flag ? -r : r;
}
inline void wr(long long x){
	if(!x){
		putchar('0');
		return;
	}
	static char buf[105];
	int cnt = 0;
	while(x) buf[++cnt] = (x % 10) ^ '0',x /= 10;
	while(cnt) putchar(buf[cnt--]);
}
int c,t,n,k;
vector<int> g[1000005];
int d[1005][1005];
int fa[1000005];
int fd(int x){
	return (x == fa[x] ? x : (fa[x] = fd(fa[x])));
}
void dfs(int o,int p,int z,int fa){
	d[o][p] = z;
	for(int y : g[p]){
		if(y == fa) continue;
		dfs(o,y,z + 1,p);
	}
}
int b[1000005],sp;
int ans =1e9;
void dfs2(int p){
	if(sp == k){
		for(int i = 1;i <= n;i++) fa[i] = i;
		int cnt = k;
		for(int i = 1;i <= sp;i++){
			for(int j = i + 1;j <= sp;j++){
				for(int x : g[b[i]]){
					if(x == b[j]){
						x = fd(x);
						int y = fd(b[i]);
						if(x == y) continue;
						else fa[x] = y,cnt--;
					}
				}
			}
		}
		if(cnt <= 2){
			int dans = 0;
			for(int i = 1;i <= n;i++){
				int r = 1e9;
				for(int j = 1;j <= sp;j++){
					r = min(r,d[i][b[j]]);
				}
				dans = max(dans,r);
			}
			ans = min(ans,dans);
		}
		
		return;
	}
	if(p >= n + 1) return;
	for(int i = p;i <= n;i++){
		b[++sp] = i;
		dfs2(i + 1);
		sp--;
	}
}
inline void sv(){
	n = read(),k = read();
	for(int i = 1;i <= n;i++) g[i].clear();
	for(int i = 1;i < n;i++){
		int x = read(),y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1;i <= n;i++) dfs(i,i,0,0);
	ans = 1e9;
	dfs2(1);
	wr(ans),putchar('\n');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),t = read();
	while(t--) sv();
	return 0;
}
