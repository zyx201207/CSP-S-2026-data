#include<bits/stdc++.h>
using namespace std;
const int N=5e5+510;//N=n+m
int C,n,m,d,qq;
long long we[N];
struct quee{
	int s,t,id;
}que[N];
bool cmp1(quee xxx,quee yyy){
	return xxx.s<yyy.s;
}
long long ans[N];
struct node{
	int v,w;
};
vector<node> e[N];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
long long dis[N];
bool vis[N];
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	while(q.size()) q.pop();
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push(make_pair(0,st));
	int u,v,w;
	int len;
	while(q.size()){
		u=q.top().second;
		q.pop();
		if(vis[u]==true) continue;
		len=e[u].size();
		for(int i=0;i<len;i++){
			v=e[u][i].v;
			w=e[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(vis[v]==false) q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>C>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>we[i];
	}
	//linenumber=m+1~m+n;
	int k,sta,lnum,tim;
	for(int i=1;i<=n;i++){//subwayline
		lnum=m+i;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sta>>tim;
			e[lnum].push_back(node{sta,tim});
			e[sta].push_back(node{lnum,tim});
		}
	}
	for(int i=1;i<=qq;i++){
		cin>>que[i].s>>que[i].t;
		que[i].id=i;
	}
	sort(que+1,que+qq+1,cmp1);
	for(int i=1;i<=qq;i++){
		if(que[i].s!=que[i-1].s){
			dij(que[i].s);
		}
		ans[que[i].id]=dis[que[i].t]+we[que[i].s]+we[que[i].t];
	}
	for(int i=1;i<=qq;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
