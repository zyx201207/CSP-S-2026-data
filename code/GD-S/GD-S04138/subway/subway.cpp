#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int M=500010,N=510;
int c,n,m,d,q,s,e,t[M][21],from[M],pre[M];
ll dis[M];
ll w[M],k[N];
bool status[M][N];
vector<int>G[M];
map<int,bool>vis[M];
map<PII,int>beline;
struct Node{
	ll dis;
	int id;
	bool operator>(const Node &a)const{
		return dis>a.dis;
	}
};
priority_queue<Node,vector<Node>,greater<Node> >dl;
void dijkstra(int start,int fsub){
	from[start]=fsub;
	while(!dl.empty())dl.pop();
	dis[start]=w[start]+t[start][fsub];
	status[start][fsub]=1;
	dl.push({dis[start],start});
	while(!dl.empty()){
		Node now=dl.top();
		dl.pop();
		int u=now.id;
//		cout<<u<<":";
//		status[start][from[start]]=1;
		for(auto v:G[u]){
//			cout<<v<<" ";
			if(u==start||vis[v][from[u]]){
				if(dis[v]>dis[u]){
					dis[v]=dis[u];
					from[v]=from[u];
					pre[v]=u;
					dl.push({dis[v],v});
				}
			}else{
				if(dis[v]>dis[u]+t[u][beline[{u,v}]]+t[u][from[u]]){
					if(v==e&&from[e]!=0){
						if(dis[v]+t[v][from[v]]<=dis[u]+t[u][beline[{u,v}]]+t[v][from[u]]+t[u][from[u]])continue;
					}
					dis[v]=dis[u]+t[u][beline[{u,v}]]+t[u][from[u]];
					from[v]=beline[{u,v}];
					pre[v]=u;
					dl.push({dis[v],v});
				}
			}
		}
//		cout<<endl;
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		int tmpa=0,tmpt=0,lasta=0;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&tmpa,&tmpt);
			if(j>=2){
				G[lasta].emplace_back(tmpa);
				G[tmpa].emplace_back(lasta);
				if(beline[{lasta,tmpa}]==0||beline[{lasta,tmpa}]>t[lasta][i])beline[{lasta,tmpa}]=i;
				if(beline[{tmpa,lasta}]==0||beline[{tmpa,lasta}]>tmpt)beline[{tmpa,lasta}]=i;
			}
			t[tmpa][i]=tmpt;
			vis[tmpa][i]=1;
			lasta=tmpa;
		}
	}
	
	while(q--){
		scanf("%d%d",&s,&e);
		for(int i=1;i<=m;i++)dis[i]=1e17;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(vis[s][i]){
				memset(from,0,sizeof from);
				memset(status,0,sizeof status);
				memset(pre,0,sizeof pre);
				memset(status,0,sizeof status);
				dijkstra(s,i);
				ans=max(ans,dis[e]+w[e]+t[e][from[e]]);
//				int final=e;
//				while(final!=0){
//					cout<<final<<"<- ";
//					final=pre[final];
//				}cout<<endl;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
