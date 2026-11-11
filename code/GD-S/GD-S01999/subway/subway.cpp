#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q;
int s,e;
vector<pair<int,int>> a[2000007];
// 1    - m    地铁口    i     1-m
// m+1  - 2m+1 站厅      i+m 
// 2m+2 - 3m+2 线路站台  j+2m+2

int l[500007];

int ls;
unordered_map<int,int> g[500007];
int gx(int x,int y){
	if(!g[x][y]) g[x][y]=++ls;
	return g[x][y];
}
 
long long dis[2000007];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> qq;

void dij(){
	memset(dis,0x3f,sizeof(dis));
	while(!qq.empty()) qq.pop();
	dis[s]=0;
	qq.push({0,s});
	
	while(!qq.empty()){
		int u=qq.top().second;
		long long w=qq.top().first;
		qq.pop();
		if(dis[u]!=w) continue;
		//if(dis[e]!=dis[0]) break;
		if(dis[u]>dis[e]) continue;
		
		for(auto i:a[u]){
			int v=i.first;
			long long ww=w+1LL*i.second;
			if(ww<dis[v]){
				dis[v]=ww;
				qq.push({dis[v],v});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	
	//cin>>c>>n>>m>>d>>q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	ls=2*m+2;
	for(int i=1;i<=m;i++){
		int w;
		//cin>>w;
		scanf("%d",&w);
		a[i].push_back({i+m,w}); // 地铁口到站厅 
		a[i+m].push_back({i,w}); 
	}
	for(int i=1;i<=n;i++){
		int k;
		//cin>>k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int w;
			scanf("%d %d",&l[j],&w);
			int oo=gx(l[j],i); // l[j] 站 i 线路站台 
			a[l[j]+m].push_back({oo,w}); // 站厅到站台 
			a[oo].push_back({l[j]+m,w}); 
		}
		for(int j=1;j<k;j++){
			a[gx(l[j],i)].push_back({gx(l[j+1],i),0});
			a[gx(l[j+1],i)].push_back({gx(l[j],i),0});
		}
	}
	
	while(q--){
		//cin>>s>>e;
		scanf("%d %d",&s,&e);
		dij();
		//cout<<dis[e]<<endl;
		printf("%lld\n",dis[e]);
	}
	
	return 0;
}

// O( q*dm*log(dm) )

// 24,25: 1e5*1e7*24
// 22,23: 1e5*1e6*21
// 20,21: 同1

// 16-19: 特殊性质可以看看 
// 12-15: 2e3*4e5*17, 得考虑特殊性质
// 9-11: 1e5*3e3*12 = 3e9

// log(10^7)=24
// 31: 2e9
// 30: 1e9
// 29: 5e8
// 28: 2.5e8
// 27: 1.25e8
// 26: 6e7
// 25: 3e7
// 24: 1.5e7
// 23: 7.5e6
// 22: 3.7e6
// 21: 1.8e6
// 20: 9e5
// 19: 4.5e5
// 18: 2.2e5
// 17: 1.1e5
// 16: 5e4
// 15: 2.5e4
// 14: 1.2e4
// 13: 6e3
// 12: 3e3
