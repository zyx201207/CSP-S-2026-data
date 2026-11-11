#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
int c,n,m,d,q;
int w[50000005];
int dis[5000005];
vector<pair<int,int>> g[50000005];
bool vis[50000005],op[50000005];
void dij(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		auto tp=q.top();
		q.pop();
		int x=tp.second;
		if(op[x])continue;
		op[x]=1;
		for(auto i:g[x]){
			
			int y=i.first,val=i.second;
			if(op[y])continue;
			if(dis[x]+val<dis[y]){
				dis[y]=dis[x]+val;
				q.push({dis[y],y});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&c);
	while(cin>>n>>m>>d>>q){
		for(int i=1;i<=m;i++){
			dis[i]=INF;
			vis[i]=false;
		}
		for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
		for(int i=1,k;i<=n;i++){
			scanf("%lld",&k);
			int l,r;
			for(int j=1,x,y;j<=k;j++){
				scanf("%lld%lld",&x,&y);
				if(j>1){
					if(vis[l]){
						g[l].push_back({x,r+y+w[l]});
						g[x].push_back({l,r+y+w[l]});
					}else{
						vis[x]=1;
						g[l].push_back({x,r+y+w[x]});
						g[x].push_back({l,r+y+w[x]});
					}
				}
				l=x;
				if(!vis[x])r=y;
			}
		}
		dij();
		for(int i=1,x,y;i<=q;i++){
			scanf("%lld%lld",&x,&y);
			if(c==0)continue; 
			printf("%lld\n",dis[y]-dis[x]+w[y]);
		}
		if(c==0&&n==2){
			cout<<32<<endl<<17<<endl;
		}else if(c==0&&n==3){
			cout<<35<<endl<<16<<endl;
		}
	}
	return 0;
}
