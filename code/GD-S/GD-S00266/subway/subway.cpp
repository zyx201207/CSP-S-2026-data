#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int>
const int M = 5e5+5;
const int N = 550;
int c,n,m,d,Q;
vector<int> point[M];
int w[M],k[N],a[N][50],t[N][50],fu[M],fu_q[M];
int dfs(int s,int e){
	priority_queue<pa,vector<pa>,greater<pa>> q;
	q.push({0,s});
	while(q.size()){
		pa u = q.top();q.pop();
		if(u.first > fu[u.second] && fu_q[u.second] == Q) continue;
		int idx = u.second;
		if(u.second == e) return u.first;
		for(const int x : point[idx]){
			int gd = 0;
			int l = 1, r = k[x];
			while(l <= r){
				int mid = (l + r) >> 1;
				if(a[x][mid] == idx) { gd = mid; break; }
				else if(a[x][mid] < idx) l = mid + 1;
				else r = mid - 1;
			}
			int tp = u.first + t[x][gd];
			for(int i = 1; i <= k[x]; i++){
				int to = a[x][i];
				if(to == idx) continue;
				int time = tp + t[x][i];
				if(time < fu[to] || fu_q[to] != Q) {
					fu[to] = time;
					fu_q[to] = Q;
					q.push({time,to});
				}
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i = 1; i <= m; i++) cin>>w[i];
	for(int i = 1; i <= n; i++){
		cin>>k[i];
		for(int j = 1; j <= k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			point[a[i][j]].push_back(i);
		}
		sort(a[i]+1,a[i]+1+k[i]);
	}
	
	while(Q--){
		int x,y;cin>>x>>y;
		cout<<dfs(x,y) + w[x] + w[y]<<"\n";
	}
	return 0; 
} 
