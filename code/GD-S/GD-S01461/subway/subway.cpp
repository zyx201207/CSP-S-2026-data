#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
#define ll long long
struct poi{
	int tto,nxt;
	ll w;
}en[10*N];
struct dij{
	int id;
	ll d;
	bool operator<(const dij &x)const{
		return d>x.d;
	}
};
struct hc{
	int xian;
	ll sj;
};
int tot,head[10*N];
void add(int u,int vv,int ww){
	++tot;
	en[tot].tto=vv;
	en[tot].nxt=head[u];
	en[tot].w=ww;
	head[u]=tot;
}
void adde(int u,int v,ll w){
	add(u,v,w);add(v,u,w);
//	cout<<"JIANTU::::"<<u<<" "<<v<<" "<<w<<"\n";
}
vector<hc> rd[N];
int mp[505][30000];
int cnt,len=0;
int hs(int x,int y){
	if(mp[x][y]!=0)return mp[x][y];
	cnt++;
	mp[x][y]=cnt;
	return cnt;
}
priority_queue<dij>q;
ll dist[30000],vis[30000],inf=1e18,dis[505][505];
int c,n,m,dd,qry,hx[N];
void Dijst(int s){
	for(int i=0;i<=cnt;i++){
		dist[i]=inf;vis[i]=0;
	}
	dist[s]=0;
	while(q.empty()==0)q.pop();
	q.push((dij){s,0
	});
	while(q.empty()==0){
		dij tp=q.top();q.pop();
		int u=tp.id;
	//	cout<<"MAN:::"<<u<<" "<<dist[u]<<" "<<head[u]<<"\n";
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=en[i].nxt){
			int v=en[i].tto;
		//	cout<<"_________________________"<<v<<"  "<<"??????";
			if(dist[v]>dist[u]+en[i].w){
				dist[v]=dist[u]+en[i].w;
		//		cout<<"________________________"<<" "<<v<<"  "<<en[i].w<<"   ";
				q.push((dij){v,dist[v]
				});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[s][hs(i,0)]=dist[hs(i,0)];
		//dis[hs(i,0)][s]=dist[hs(i,0)];
	}
}
ll wk[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>dd>>qry;
	for(int i=1;i<=m;i++){
		cin>>wk[i];
	}
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		for(int j=1;j<=tmp;j++){
			int x,t;
			cin>>x>>t;
			rd[x].push_back((hc){i,t});
		}
	}
	len=0;
	for(int i=1;i<=m;i++){
		if(rd[i].size()>1){
			hx[i]=++len;
			for(int j=0;j<rd[i].size();j++){
				adde(hs(rd[i][j].xian,0),hs(rd[i][j].xian,hx[i]),0);
				adde(hs(0,hx[i]),hs(rd[i][j].xian,hx[i]),rd[i][j].sj);
			}
		}
	}
	for(int i=1;i<=n;i++){
		Dijst(hs(i,0));
	}
	for(int i=1;i<=qry;i++){
		int s,t;
		cin>>s>>t;
		ll minn=inf;
		for(int j=0;j<rd[s].size();j++){
			for(int k=0;k<rd[t].size();k++){
				minn=min(minn,rd[s][j].sj+rd[t][k].sj+dis[hs(rd[s][j].xian,0)][hs(rd[t][k].xian,0)]);
		//		cout<<"TIAOSHI"<<s<<' '<<t<<" "<<rd[s][j].xian<<" "<<rd[t][k].xian<<" "<<dis[hs(rd[s][j].xian,0)][hs(rd[t][k].xian,0)]<<"\n";
			}
		}
		cout<<minn+wk[s]+wk[t]<<"\n";
	}
//	cout<<"TSTSTSTSTSTST::::"<<hs(1,0)<<" "<<hs(2,0)<<" "<<dis[2][5]<<"\n";
}
