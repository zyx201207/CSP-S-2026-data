#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,ans;
int vis[500005],k[505],a[501][500001],t[501][500001],w[500005];
vector<pair<int, int> >v[1000];
void dfs(int x,int y, int sum){
	vis[x] = 1;
	if(x == y){
		ans = min(ans, sum);
		return ; 
	}
	for(int i = 0; i<v[x].size(); i++){
		pair<int, int> e;
		e = v[x][i];
		int id = e.first;
		sum += e.second;
		for(int i = 1; i<=k[id]; i++){
			if(!vis[a[id][i]]){
				dfs(a[id][i], y, sum+t[id][i]);
				vis[a[id][i]] = 0;
			}
		}
//		sum -= e.second;
	}
}
int tim[500005],cnt[500005];
void solve20(){
	int minn = 1e6;
	
	for(int i = 1; i<=m; i++){
		cin>>w[i];
	}for(int i = 1; i<=n; i++){
		cin>>k[i];
		for(int j = 1; j<=k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]] += i;
			v[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}for(int i = 1; i<=n; i++){
		for(int j = 0; j<v[i].size(); j++){
			tim[i]+=v[i][j].second;
		}
		if(v[i].size() == 2){
			minn = min(tim[i], minn);
		}
	}for(int i =1; i<=q; i++){
		int x, y;
		cin>>x>>y;
		if(cnt[x] == cnt[y]&&cnt[x]<3){
			cout<<w[x]+w[y]+v[x][0].second+v[y][0].second;
			continue;
		}else if(cnt[x]==cnt[y]){
			int t1 = 1e6;
		for(int j = 0; j<v[x].size(); j++){
			for(int h = 0; h<v[y].size(); h++){
				if(v[x][i].first == v[y][i].first){
					t1 = min(t1, v[x][i].second+v[y][i].second);
				}
			}
		}
			cout<<t1+w[x]+w[y];
			continue;
		}else{
			cout<<minn+v[x][0].second+v[y][0].second+w[x]+w[y];
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("sumbay.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c == 20||c == 21){
		solve20();
	}
	for(int i = 1; i<=m; i++){
		cin>>w[i];
	}for(int i = 1; i<=n; i++){
		cin>>k[i];
		for(int j = 1; j<=k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}
	for(int i = 1; i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans = 0;
		dfs(x,y,0);
		cout<<ans+w[x]+w[y];
		memset(vis, 0,sizeof(vis));
	}
}

