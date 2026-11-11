#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
typedef pair<int,pair<int,pair<int,int> > > pii;// dist,u,id,tl
const int N=5e5+50;
int c,n,m,dm,q;
int w[N];
int head[N],tot=1;
int d[N];
struct Edge{
	int to,nxt,t,id;
}e[N*2];
void add(int u,int v,int t,int id){
	e[++tot]={v,head[u],t,id},head[u]=tot;
}
int dij(int s,int t){
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,{s,{0,w[s]}}});
	while(!q.empty()){
		pii tmp=q.top();q.pop();
		int dis=tmp.fi,u=tmp.se.fi,id=tmp.se.se.fi,tl=tmp.se.se.se;
		if(dis>d[u])continue;
		if(u==t)return d[u]+tl+w[t];
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,t=e[i].t,idd=e[i].id;
			if(d[v]>d[u]+(idd==id?0:tl+e[i^1].t)){
				d[v]=d[u]+(idd==id?0:tl+e[i^1].t);
				q.push({d[v],{v,{idd,t}}});
			}
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dm>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int j=1,a,t,la=0,lt=0;j<=k;++j){
			cin>>a>>t;
			if(la&&lt)add(la,a,t,i),add(a,la,lt,i);
			la=a,lt=t;
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<dij(x,y)<<'\n';
	}
	return 0;
} 
