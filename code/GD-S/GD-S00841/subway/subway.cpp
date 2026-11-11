#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
typedef long long ll;
ll w[1010];
int tts[50][1010];
struct StationLinkInfo{
	int nxt,line;
};
vector<StationLinkInfo> mp[1010];
bool vis[50][1010];

ll c,n,m,d,q;
struct Node{
	int id,t,sid;
};
ll bfs(int x, int y){
	memset(vis, false, sizeof vis);
	queue<Node> q;
	int ssid = 0;
	for(int i = 1; i <= n; i++){
		if(tts[i][x] == 0) continue;
		q.push({x,tts[i][x],i});
		vis[i][x] = true;
		ssid++;
	}
	ll ans = INT_MAX;
	while(q.size()){
		auto cur = q.front();
		q.pop();
		//cout << cur.id << '(' << cur.sid << ')' << endl;
		if(cur.id == y){
			ans = min(ans,cur.t + tts[cur.sid][y] + w[y] + w[x]);
			vis[cur.sid][y] = false;
			continue;
			//return cur.t + tts[cur.sid][y] + w[y] + w[x];
		}

		
		for(const auto& s : mp[cur.id]){
			//cout << cur.id << '(' << cur.sid << ')' << '-' << s.nxt << '(' << s.line << ')' << endl;
//			for(int i = 1; i <= n; i++){
//				if(tts[i][s.nxt] == 0) continue;
				//cout << cur.t << '+' << cur.id << '(' << cur.sid << ')' << "->" << s.nxt << '(' << s.line << ')' << ": " << tts[s.line][s.nxt] << endl;
				if(vis[s.line][s.nxt] || (s.line != cur.sid && s.nxt != cur.id)) continue;
				if(s.line == cur.sid){
					//cout << cur.id << '(' << cur.sid << ')' << '-' << s.nxt << '(' << s.line << ')' << endl;
					q.push({s.nxt, cur.t, cur.sid});
					vis[s.line][s.nxt] = true;
				}
				else{
					//cout << cur.id << '(' << cur.sid << ')' << "->" << s.nxt << '(' << s.line << ')' << endl;
					q.push({s.nxt, cur.t + tts[cur.sid][s.nxt] + tts[s.line][s.nxt], s.line});
					vis[s.line][s.nxt] = true;
				}
				
				//cout << s.line << ':' << s.nxt << endl;
//			}
		}
	}
	return ans;
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int la = 0;
		vector<int> ss;
		for(int j = 1; j <= k; j++){
			int a,t;
			cin >> a >> t;
			tts[i][a] = t;
			ss.push_back(a);
		}
		for(const int& s1 : ss){
			for(const int& s2 : ss){
				mp[s1].push_back({s2,i});
				mp[s2].push_back({s1,i});
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << bfs(x,y) << endl;
	}
}
