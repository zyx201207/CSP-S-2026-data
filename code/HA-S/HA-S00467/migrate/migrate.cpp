#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N=5010;
int n, d;
struct node{
	int to, len;
	bool operator<(const node& other)const{
		return len>other.len;
	}
};
vector<node>g[MAX_N];
int arr[MAX_N];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(arr[i]-arr[j])<=d){
				g[i].push_back({j, 1});
			}
		}
	}
}

int dis[MAX_N][MAX_N];
bool vis[MAX_N];
void dij(int s){
	priority_queue<node>pq;
	pq.push({s, 0});
	for(int i=1;i<=n;i++)dis[s][i]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++)vis[i]=false;
	dis[s][s]=0;
	while(!pq.empty()){
		node tmp=pq.top();
		pq.pop();
		int to=tmp.to, len=tmp.len;
		if(vis[to])continue;
		vis[to]=true;
		for(node v:g[to]){
			if(dis[s][v.to]>len+v.len){
				dis[s][v.to]=len+v.len;
				pq.push({v.to, dis[s][v.to]});
			}
		}
	}
}
bool st[MAX_N];
int cnt[MAX_N][MAX_N];
void dfs(int x){
	int sum=-1;
	int l=0, r=0;
	for(int i=1;i<=n;i++){
		if(sum==-1&&st[i]==true)l=i;
		if(st[i]==true){
			sum++;
			r=i;
		}
	}
	if(dis[l][r]==sum)cnt[l][r]++;
	for(node &v:g[x]){
		st[v.to]=true;
		dfs(v.to);
		st[v.to]=false;
	}
}

void prepare(){
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		st[i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=0;
		}
	}
}


signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		prepare();
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		init();
		for(int i=1;i<=n;i++){
			dij(i);
		}
		for(int i=1;i<=n;i++){
			st[i]=true;
			dfs(i);
			st[i]=false;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)res++;
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
