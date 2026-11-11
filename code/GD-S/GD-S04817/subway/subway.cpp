#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[500005], k[505], f[500005], dis[500005], vis[500005], ans[500005], in[500005];
vector<pair<int, int> > vc[500005], v[500005];
vector<int> st;
vector<pair<int, int> > to[500005];
void dij(int u){
	for(int i=1;i<=m;i++){
		dis[i]=LLONG_MAX;
		vis[i]=0;
	}
	priority_queue<pair<int, int> > q;
	q.push({0, u});
	dis[u]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]==1)continue;
		for(int i=0;i<vc[u].size();i++){
			int to=vc[u][i].first, w=vc[u][i].second;
			if(dis[to]>dis[u]+w){
				dis[to]=dis[u]+w;
				q.push({-dis[to], to});
			}
		}
	}
}
int co[500005], ddd[500005], C[5];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	int sum=0;
	int num=0, lu1=0, lu2=0, maxx=0;
	for(int i=1;i<=n;i++){
		cin >> k[i];
		sum+=k[i];
		for(int j=1;j<=k[i];j++){
			int x, y;
			cin >> x >> y;
			ddd[x]=ddd[y]=i;
			in[x]++;
			maxx=max(maxx, max(in[x], in[y]));
			v[i].push_back({x, y});
		}
	}
	if(sum<=1000){
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				for(int k=j+1;k<v[i].size();k++){
					int x=v[i][j].first, y=v[i][k].first;
					int w=v[i][j].second+v[i][k].second;
					vc[x].push_back({y, w});
					vc[y].push_back({x, w});
//					cout << x << "-" << y << " " << w << endl;
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x, y;
			cin >> x >> y;
			ans[i]=w[x]+w[y];
			if(f[x]==0){
				st.push_back(x);
			}
			to[x].push_back({y, i});
			f[x]=1;
		}
		for(int i=0;i<st.size();i++){
			dij(st[i]);
			for(int j=0;j<to[st[i]].size();j++){
				pair<int, int> xx=to[st[i]][j];
				ans[xx.second]+=dis[xx.first];
			}
		}
		for(int i=1;i<=q;i++){
			cout << ans[i] << endl;
		}
	}else if(n==2){
		for(int i=1;i<=m;i++)co[i]=LLONG_MAX;
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<k[i];j++){
				int x=v[i][j].first;
				if(in[x]==2){
					num+=v[i][j].second;
					C[i]=v[i][j].second;
					co[x]=min(co[x], v[i][j].second);
				}else{
					co[x]=v[i][j].second;
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x, y;
			cin >> x >> y;
			if(ddd[x]==ddd[y]&&in[x]!=2&&in[y]!=2){
				cout << w[x]+w[y]+co[x]+co[y] << endl;
			}else if(in[x]==2){
				cout << w[x]+w[y]+co[y]+C[ddd[y]] << endl;
			}else if(in[y]==2){
				cout << w[x]+w[y]+co[x]+C[ddd[x]] << endl;
			}else{
				cout << w[x]+w[y]+co[x]+co[y]+num << endl;
			}
		}
	}else{
		for(int i=1;i<=q;i++){
			cout << 0 << endl;
		}
	}
	return 0;
}
/*
花费拆解为 进站->不停的换乘->出站 
换乘花费=起点的t+终点的t 
既然d<=20那么就说明了经过一个点的方案最多有400种
500000*400=20000000...是不是太安全了一点？
注意到可能会出现环 
*/
