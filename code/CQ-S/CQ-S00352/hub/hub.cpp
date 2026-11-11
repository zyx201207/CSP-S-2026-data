#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define _1 first
#define _2 second
using namespace std;
const int N=4000+5;
int c,t,n,k;
vector<int> h[N];
bool vis[N][N];
ll dn=LLONG_MAX; 
bool sy[N];
bool jc(){
	vector<int> ls;
	ls.clear();
	for(int i=1;i<=n;i++){
		if(sy[i]){
			ls.push_back(i);
		}
	}
	int cnt=0;
	vector<int> lss[N];
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(vis[ls[i]][ls[j]]==1){
				lss[ls[i]].push_back({ls[j]});
				lss[ls[j]].push_back({ls[i]});
			}
		}
	}
	vector<bool> vis(n+5,0);
	for(int i=0;i<k;i++){
		if(vis[ls[i]])continue;
		queue<int> q;
		q.push(ls[i]);
		while(!q.empty()){
			int u=q.front();
			vis[u]=1;
			q.pop();
			for(int v:lss[u]){
				if(vis[v])continue;
				q.push(v);
			}
		}
		cnt++;
	}
	if(cnt>2){
		return 0;
	}
	return 1;
}
ll js(){
	vector<int> ls;
	vector<int> lss[N];
	ls.clear();
	for(int i=1;i<=n;i++){
		if(sy[i]){
			ls.push_back(i);
		}
		lss[i]=h[i];
	}
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			lss[ls[i]].push_back(ls[j]);
			lss[ls[j]].push_back(ls[i]);
		}
	}
	ll mx=0;
	for(int i=1;i<=n;i++){
		vector<ll> dis(n+5,0x3f);
		queue<int> q;
		dis[i]=0;
		q.push(i); 
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:lss[u]){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		ll mn=1e9+7;
		for(int j=0;j<k;j++){
			mn=min(mn,dis[ls[j]]);
		}
		mx=max(mx,mn);
	}
	return mx;
}
void dfs(int wz,int sl){
	if(sl==k){
		if(jc()){
			dn=min(dn,js());
		}
		return;
	}
	if(wz==n){
		return;
	}
	sy[wz+1]=1;
	dfs(wz+1,sl+1);
	sy[wz+1]=0;
	dfs(wz+1,sl);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		dn=1e9+7;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			h[i].clear();
			for(int j=1;j<=n;j++){
				vis[i][j]=0;
			}
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			h[u].push_back(v);
			h[v].push_back(u);
			vis[u][v]=vis[v][u]=1;
		}
		dfs(0,0);
		cout<<dn<<'\n';
	}
	return 0;
}
/*
累死我了终于做到最后一题了
我的妈呀怎么这么难 

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/ 
