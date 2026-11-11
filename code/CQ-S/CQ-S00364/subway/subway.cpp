#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pint=pair<int,ll>;
const int N=500+10,M=5e5+10;
int ceshi,n,m,d,qu;
ll a[M];
vector<pint> mp[N+M];
namespace sub1{
	ll dis[N+M];
	bool vis[N+M];
	ll dij(int s,int t){
//		cout<<s<<" "<<t<<" ?\n";
		priority_queue<pair<ll,int>> q;
		for(int i=1;i<=n+m;i++){
			dis[i]=0x3f3f3f3f3f3f3f3f;
			vis[i]=0;
		}
		q.push({-0,s+n});
		dis[s+n]=0;
		while(q.size()){
			pair<ll,int> ew=q.top();
			q.pop();
			int u=ew.second;
//			cout<<dis[u]<<" "<<u<<" !\n";
			if(vis[u])continue;
			vis[u]=1;
			if(u==t+n)break;
			for(pint wsdr:mp[u]){
				int v=wsdr.first;
				ll w=wsdr.second;
				if(vis[v]==0&&dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					q.push({-dis[v],v});
				}
			}
		}
		return dis[t+n];
	}
	void main(){
		for(int _=1;_<=qu;_++){
			int st,ed;
			cin>>st>>ed;
			cout<<a[st]+a[ed]+dij(st,ed)<<"\n";
		}
	}
}
namespace sub2{
	ll dis1[N+M],dis2[N+M];
	bool vis[N+M];
	void dij(){
		priority_queue<pair<ll,int>> q;
		for(int i=1;i<=n+m;i++)dis1[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
		q.push({-0,1});
		dis1[1]=0;
		while(q.size()){
			pair<ll,int> ew=q.top();
			q.pop();
			int u=ew.second;
			if(vis[u])continue;
			vis[u]=1;
			for(pint wsdr:mp[u]){
				int v=wsdr.first;
				ll w=wsdr.second;
				if(vis[v]==0&&dis1[v]>dis1[u]+w){
					dis1[v]=dis1[u]+w;
					q.push({-dis1[v],v});
				}
			}
		}
		for(int i=1;i<=n+m;i++)dis2[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
		if(n==1)return;
		q.push({-0,2});
		dis2[2]=0;
		while(q.size()){
			pair<ll,int> ew=q.top();
			q.pop();
			int u=ew.second;
			if(vis[u])continue;
			vis[u]=1;
			for(pint wsdr:mp[u]){
				int v=wsdr.first;
				ll w=wsdr.second;
				if(vis[v]==0&&dis2[v]>dis2[u]+w){
					dis2[v]=dis2[u]+w;
					q.push({-dis2[v],v});
				}
			}
		}
	}
	void main(){
		dij();
		for(int _=1;_<=qu;_++){
			int st,ed;
			cin>>st>>ed;
			cout<<a[st]+a[ed]+min(dis1[st+n]+dis1[ed+n],dis2[st+n]+dis2[ed+n])<<"\n";
		}
	}
}
bool px(pint a,pint b){
	if(a.second!=b.second)return a.second<b.second;
	return a.first<b.first;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway3.in","r",stdin);
//	freopen("dma.out","w",stdout);
	cin>>ceshi>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int num,t;
			cin>>num>>t;
			mp[i].push_back({n+num,t});
			mp[n+num].push_back({i,t});
		}
		sort(mp[i].begin(),mp[i].end(),px);
	}
	if(1<=ceshi&&ceshi<=8){
		sub1::main();
		return 0;
	}
	if(20<=ceshi&&ceshi<=21){
		sub2::main();
		return 0;
	}
	
	return 0; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

20 2 4 2 3
0 0 0 0
3 1 1 2 10 3 100
2 2 1000 4 10000
1 4
3 4
2 4

ll ds[N][N];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int zz1=0,zz2=0,n1=mp[i].size(),n2=mp[j].size();
			
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ds[j][i]=ds[i][j];
*/
