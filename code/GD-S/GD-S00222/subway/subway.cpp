#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int c,n,m,d,p;
int w[MAXN];
vector<pair<int,int> > tu[MAXN]; 
int tinode[25][MAXN];
int ans[MAXN];
int bfs(int start,int end){
	for(int i = 1;i<=m;i++){
		ans[i] = 0x3f3f3f3f;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	ans[start] = 0;
	while(!q.empty()){
		int u = q.top().second;
		int v = q.top().first;
		q.pop();
		if(u == end){
			return ans[u];
		}
		for(int i = 0;i<tu[u].size();i++){
			int du = tu[u][i].first;
			int dv = tu[u][i].second;
			if(ans[du]<ans[u]+dv){
				ans[du] = ans[u]+dv;
				q.push({du,ans[du]});
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i<=m;i++)
		cin>>w[i];
	for(int i = 1;i<=n;i++){
		int take;
		cin>>take;
		int biao;
		for(int j = 1;j<=take;j++){
			int len,time;
			cin>>len>>time;
			tinode[i][len] = time;
			if(j == 1) biao = j;
			tu[biao].push_back({len,time});
			biao = len;
		}
	}
	for(int i = 1;i<=p;i++){
		int start,end;
		cin>>start>>end;
		cout<<w[start]+w[end]+bfs(start,end)<<endl;
	}
	return 0;
}
