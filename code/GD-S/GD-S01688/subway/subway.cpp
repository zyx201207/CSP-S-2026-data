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

const int MM = 500005;
bool vis[2][MM]; // 是否进过优先队列 
int w[MM], dist[2][MM]; // w出入起点和终点时间，dist最小步行时间 
struct zt{
	int to, t;
};
vector <zt> z[2][MM];

struct f{
	int id, lx, dis;
	bool operator <(const f &other) const 
	{
		return other.dis < dis;
	}
}u;
priority_queue <f> q;

int c, n, m, d, xw; // n为地铁线路数 ，m为地铁站数，xw为出行计划数 
void cl(){
	for(int i = 1;i <= n;i++){
		vis[0][i] = false;
		dist[0][i] = 1e18;
	}
	for(int i = 1;i <= m;i++){
		vis[1][i] = false;
		dist[1][i] = 1e18;
	} 
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), xw = read();
	for(int i = 1;i <= m;i++)
		w[i] = read();
	for(int i = 1;i <= n;i++){
		int k = read();
		for(int j = 1;j <= k;j++){
			int num = read(), tm = read();
			z[0][i].push_back({num, tm});
			z[1][num].push_back({i, tm});
		}
	}
	
	int st, en;
	while(xw--){
		st = read(), en = read();
		cl(); // 清空 
		dist[1][st] = 0; q.push({st, 1, 0});
		while(!q.empty()){
			u = q.top(); q.pop();
			if(vis[u.lx][u.id] == true)
				continue;
			vis[u.lx][u.id] = true;
			if(u.lx == 1 && u.id == en){
				while(!q.empty())
					q.pop();
				break;
			}
			for(int i = 0;i < z[u.lx][u.id].size();i++){
				zt v = z[u.lx][u.id][i];
				if(u.dis+v.t < dist[(u.lx+1)%2][v.to]){
					dist[(u.lx+1)%2][v.to] = u.dis+v.t;
					q.push({v.to, (u.lx+1)%2, u.dis+v.t});
				}
			}
		}
		cout << w[st]+w[en]+dist[1][en] << '\n';
	}
} 
