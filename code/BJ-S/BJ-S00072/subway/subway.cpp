#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int id,time;
};
vector<node> v[505];//储存线路上的地铁站及路线站台到地铁站站厅的距离
vector<node> v2[500005];//储存每个地铁站在哪个线路上及地铁站站厅到路线站台的距离
int w[500005],vis[500005];
int c,n,m,d,q;
int minn;
void dfs(int st,int ed,int t,int xianlu){//当前地铁站（在站台）；截止地铁站；所花费时间；上一次所在线路
	if(t>=minn){
		return;//剪枝
	}
	if(st==ed){
		minn=min(minn,t);
		return;
	}
	for(node i:v2[st]){
		if(i.id==xianlu) continue;//剪枝 同一线路上的地铁站已经在上一轮全部放入dfs
		for(node j:v[i.id]){
			if(j.id!=st&&vis[j.id]>t+i.time+j.time){
				int t=vis[j.id];
				vis[j.id]=t+i.time+j.time;
				dfs(j.id,ed,t+i.time+j.time,i.id);//t:站台->站厅->站台
				vis[j.id]=t;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[i].push_back({a,t});
			v2[a].push_back({i,t});
		}
	}
	while(q--){
		minn=1000000005;
		int x,y;
		cin>>x>>y;
		for(node i:v2[x]){
			for(node j:v[i.id]){
				dfs(j.id,y,i.time,i.id);
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
	}
	return 0;
}
