#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=505;
int len,head[maxn],edg[maxn*2],nxt[maxn*2],t[maxn*2];
int k[maxm],s[maxn][maxm],w[maxn],ans[maxn];
int dis[maxn];bool vis[maxn];
vector<int>a[maxm],sta[maxm];
int qs[maxn],qt[maxn];
bool ok[maxn];
struct qey{
	int cnt,u;
	vector<int>id;
}query[maxn];
bool cmp(qey a,qey b){
	return a.cnt>b.cnt;
}
int c,n,m,d,q;
void add(int u,int v,int i)
{
	edg[++len]=v;t[len]=s[u][i]+s[v][i];
	nxt[len]=head[u];
	head[u]=len;
}
void add_pro(int u,int i)
{
	query[u].u=u;
	query[u].cnt++;
	query[u].id.push_back(i);
}
void dijkstra(int st)
{
	priority_queue<pair<int,int> >qp;
	memset(dis,0x3f,4*n+1);
	memset(vis,0,4*n+1);
	dis[st]=0;
	qp.push({0,st});
	while(!qp.empty())
	{
		int u=qp.top().second;
		qp.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=edg[i],x=t[i];
			if(dis[u]+x<dis[v]){
				dis[v]=dis[u]+x;
				qp.push({-dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u;
			cin>>u>>s[u][i];
			for(int x=0;x<j-1;x++){
				add(a[i][x],u,i);
				add(u,a[i][x],i);
			}
			a[i].push_back(u);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qs[i]>>qt[i];
		add_pro(qs[i],i);
		add_pro(qt[i],i);
	}
	sort(query+1,query+n+1,cmp);bool f=0;
	for(int i=1;i<=n;i++){
		int u=query[i].u;
		if(!query[i].cnt)break;
		f=0;
		for(int j=0;j<query[i].cnt;j++){
			int v=query[i].id[j];
			if(ok[v])continue;
			f=1;
		}
		if(!f)continue;
		dijkstra(u);
		for(int j=0;j<query[i].cnt;j++){
			int v=query[i].id[j];
			//cout<<qs[v]<<" "<<qt[v]<<"\n";
			if(ok[v])continue;
			ok[v]=1;
			if(qs[v]!=u)swap(qs[v],qt[v]);
			ans[v]=dis[qt[v]]+w[qs[v]]+w[qt[v]];
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
