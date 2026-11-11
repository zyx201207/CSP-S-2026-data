#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
const int maxn = 1e4+3;
const int INF = 2e18;
const int N = 505;
int c,n,m,d,q;
int t[N][maxn],val[N],dis[N][maxn];
vector <int> belong[N];
vector <pii> G[N];
bool inque[N][maxn];
int spfa(int st,int ed,int rou){
	queue <pii> q;
	int ans = val[st]+val[ed];
	ans += t[rou][st];
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++) dis[i][j] = INF;
	dis[st][rou] = 0ll;	
	inque[st][rou] = 1;
	q.push({st,rou});
	while(!q.empty()){
		int x = q.front().first,pre = q.front().second;
		q.pop();
		inque[x][pre] = 0;
		for(auto it : G[x]){
			int to = it.first,tmp2 = it.second;
			if(pre == tmp2){
				if(dis[to][tmp2] > dis[x][pre]){
					dis[to][tmp2] = dis[x][pre];
					if(!inque[to][tmp2]){
						inque[to][tmp2] = 1;
						q.push({to,tmp2});
					}
				}
			}else if(pre != tmp2){
				int base = t[pre][x]+t[tmp2][x];
				if(dis[to][tmp2] > dis[x][pre] + base){
					dis[to][tmp2] = dis[x][pre] + base;
					if(!inque[to][tmp2]){
						inque[to][tmp2] = 1;
						q.push({to,tmp2});
					}
				}
			}
		}
	}
	int rec = INF;
	for(auto it : belong[ed]) rec = min(rec,ans+dis[ed][it]+t[it][ed]);
	return rec;
}

void solve(int st,int ed){
	int tot = INF;
	for(auto it : belong[st]){
		tot = min(tot,spfa(st,ed,it));
	}
	cout << tot << '\n';
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> val[i];
	for(int i = 1;i <= n;i++){
		int k;cin >> k;
		vector <int> vec;
		for(int j = 1;j <= k;j++){
			int point,time;cin >> point >> time;
			t[i][point] = time;
			belong[point].push_back(i);
			vec.push_back(point);
		}
		for(int k = 0;k < vec.size()-1;k++) G[vec[k]].push_back({vec[k+1],i});
	}
	while(q--){
		int st,ed;cin >> st >> ed;
		solve(st,ed);
	}
	return 0;
}