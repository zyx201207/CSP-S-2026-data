#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=5e5+10,inf=1e18+10;
LL c,n,m,d,r,k[510],w[500010],T;//n:地铁线路数 m:地铁站数 d:最多被几条线路经过
//ai,j 表示 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
struct node{
	LL sta,step;
};
struct edge{
	LL v,dis;
};
queue <node> q;
vector <LL> e[500010],a[N],t[N]; 
vector <edge> e1[N];
bool vis[500010];
void bfs(LL x,LL y){
	while(!q.empty()) q.pop();
	LL dis=0,ans=0;
	q.push({x,0});
	while(!q.empty()){
		LL tmp=q.front().sta,st=q.front().step;q.pop();
		vis[tmp]=1;
		if(tmp==y){
			dis=st;
		}
		for(int i=0;i<e[tmp].size();i++){
			LL v=e[tmp][i];
			if(vis[v]==0){
				q.push({v,st});
			}
		}
	}
	ans=w[x]+w[y]+T*(dis-1)*2+2*T;
	cout<<ans<<endl; 
}
struct priq{
	LL v,dis;
	bool operator < (const priq x) const{
		return dis>x.dis;
	}
};
priority_queue <priq> prq; 
LL dis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			LL x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	while(r--){
		LL x,y;
		cin>>x>>y;
		LL ans=0;
//		if(c>=12&&c<=19){
//			T=t[1][0];
//			for(int i=0;i<=m;i++){
//				e[i].clear();
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=0;j<k[i];j++){
//					for(int l=0;l<k[i];l++){
//						if(j!=l){
//							e[a[i][j]].push_back(a[i][l]);
//						}
//					}
//				}
//			}
////			cout<<"		"<<T<<endl;
//			bfs(x,y);
//		}
//		else{
			for(int i=0;i<=m;i++){
				e1[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<k[i];j++){
					for(int l=0;l<k[i];l++){
						if(j!=l){
							
							e1[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
						}
					}
				}
			}
			for(int i=1;i<=m;i++){
				dis[i]=inf;
				vis[i]=0;
			}
			dis[x]=0;
			prq.push({x,0});
			
			while(!prq.empty()){
				priq tmp=prq.top();prq.pop();
				if(dis[tmp.v]>tmp.dis||vis[tmp.v]==1) continue;
				vis[tmp.v]=1;
				
				for(int i=0;i<e1[tmp.v].size();i++){
					LL v=e1[tmp.v][i].v;
					if(!vis[v]){
						if(dis[v]>dis[tmp.v]+e1[tmp.v][i].dis){
							dis[v]=dis[tmp.v]+e1[tmp.v][i].dis;
							prq.push({v,dis[v]}); 
						}
					}
				}
			}
			ans=w[x]+w[y]+dis[y];
			cout<<ans<<endl;
//		}
	}
}

