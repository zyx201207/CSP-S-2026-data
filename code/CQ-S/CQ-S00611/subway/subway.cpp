#include <bits/stdc++.h>
using namespace std;
const int N=600005;
typedef pair<long long,int> PII;
priority_queue <PII,vector<PII>,greater<PII> > st;
int c,n,m,d,q,w[N],k[N],flag1=0,head[N],cnt,flag[505];
long long dist[505],ans[N];
vector <int> a[N],t[N];
struct que{
	int x,y,id;
}qu[N];
struct edge{
	int to,next,w;
}e[2*N];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool cmp(que x,que y){
	return x.x<y.x;
}
void dij(int u){
	memset(dist,0x7f,sizeof(dist));
	memset(flag,0,sizeof(flag));
	dist[u]=0;
	st.push({dist[u],u});
	while(!st.empty()){
		PII temp=st.top();
		st.pop();
		int idx=temp.second;
		long long distx=temp.first;
		if(flag[idx]==1) continue;
		flag[idx]=1;
		for(int i=head[idx];i!=-1;i=e[i].next){
			int v=e[i].to;
			if(dist[v]>distx+1ll*e[i].w){
				dist[v]=distx+1ll*e[i].w;
				st.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		if(k[i]>2) flag1=1;
		for(int j=1;j<=k[i];j++){
			int u,v;
			scanf("%d%d",&u,&v);
			a[i].push_back(u);
			t[i].push_back(v);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].x,&qu[i].y);
		qu[i].id=i;
	}
	if(!flag1){
		for(int i=1;i<=n;i++){
			if(a[i].size()>1){
				int u=a[i][0],v=a[i][1];
				add(u,v,t[i][0]+t[i][1]);
				add(v,u,t[i][0]+t[i][1]);
			}
		}
		sort(qu+1,qu+q+1,cmp);
		int u=0;
		for(int i=1;i<=q;i++){
			if(u!=qu[i].x){
				u=qu[i].x;
				dij(u);
			}
			ans[qu[i].id]=dist[qu[i].y]+w[qu[i].x]+w[qu[i].y];
		}
		for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}/*
0 3 3 2 3
2 2 2
2 1 3 2 4
2 2 5 3 7
2 3 9 1 11
2 3
1 2
1 3
*/
