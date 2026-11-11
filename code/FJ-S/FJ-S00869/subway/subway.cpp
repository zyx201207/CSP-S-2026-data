#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

constexpr int MAXM=500000+7;
int c,n,m,d,q,ans;
int w[MAXM],x,y,tmp;
int time[MAXM][21]={0};
int line[21][2];
bool vis[MAXM];

void dfs(int cur, int tgt, int tot, int swaptime){
	if(cur==tgt){
		if(tot<ans)ans=tot;
		return;
	}
	tot+=swaptime;
	for(int i=0;i<n;++i){
		if(time[cur][i]){
			if(line[i][0]==cur){
				if(vis[line[i][1]])continue;
				vis[line[i][1]]=true;
				dfs(line[i][1], tgt, tot+time[cur][i], time[line[i][1]][i]);
				vis[line[i][1]]=false;
			}else{
				if(vis[line[i][0]])continue;
				vis[line[i][0]]=true;
				dfs(line[i][0], tgt, tot+time[cur][i], time[line[i][0]][i]);
				vis[line[i][0]]=false;
			}
		}
	}
	return;
}

int solveA(){
	cin>>x>>y;
	ans=2147000000;
	vector<int> start;
	bool can_end[21]={0};
	for(int i=0;i<n;++i){
		if(time[x][i]){
			if(time[y][i])return ans;
			else{
				start.push_back(i);
			}
		}
	}
	size_t size=start.size();
	for(int i=0;i<size;++i){
		dfs(x, y, 0, 0);
	}
	
	return ans+w[x]+w[y];
}

void solve(){
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	c=7;
	if(c>=7&&c<=11){
		for(int i=0;i<n;++i){
			int k;
			cin>>k;
			if(k!=2)continue;
			for(int j=0;j<2;++j){
				cin>>tmp;
				line[i][0]=tmp;
				// 从线路i前往tmp站厅的时间 
				// 根据站台检索经过的线路 
				cin>>time[tmp][i];
			}
		}
		while(q--){
			cout<<solveA()<<"\n";
		}
	}	
	
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	solve();
	
	return 0;
}
