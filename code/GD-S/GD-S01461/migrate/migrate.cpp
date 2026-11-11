#include<bits/stdc++.h>
using namespace std;
const int N=2000;
#define ll long long
struct poi{
	int tto,nxt;
	int w;
}en[10*N];
struct dij{
	int id;
	int d;
	bool operator<(const dij &x)const{
		return d>x.d;
	}
};
struct hc{
	int xian;
	ll sj;
};
int n,tot,head[10*N],dis[505][505],cnt[505][505],dist[505],vis[505];
int inf=1e8;
ll d;
void add(int u,int vv,int ww){
	++tot;
	en[tot].tto=vv;
	en[tot].nxt=head[u];
	en[tot].w=ww;
	head[u]=tot;
}
void adde(int u,int v,ll w){
	add(u,v,w);add(v,u,w);
}
priority_queue<dij>q;
void Dijst(int s){
	for(int i=0;i<=500;i++){
		dist[i]=inf;vis[i]=0;
	}
	dist[s]=0;cnt[s][s]=1;
	while(q.empty()==0)q.pop();
	q.push((dij){s,0
	});
	while(q.empty()==0){
		dij tp=q.top();q.pop();
		int u=tp.id;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=en[i].nxt){
			int v=en[i].tto;
			if(dist[v]>dist[u]+en[i].w){
				cnt[s][v]=cnt[s][u];
				dist[v]=dist[u]+en[i].w;
				q.push((dij){v,dist[v]
				});
			}else{
				if(dist[v]==dist[u]+en[i].w){
					cnt[s][v]+=cnt[s][u];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[s][i]=dist[i];
	}
}
ll x[N],nm;
void sv(){
	memset(cnt,0,sizeof(cnt));
	memset(dis,0,sizeof(dis));
	tot=0;nm=0;
	memset(head,0,sizeof(head));
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[i]-x[j])<=d)adde(i,j,1);
		}
	}
	for(int i=1;i<=n;i++)Dijst(i);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				nm++;
			}
		}
	}
	cout<<nm<<"\n";
}
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)sv();
}
