#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int Q=1e5+5;
struct node{
	int v,w;
	bool operator>(const node a)const{
		return w>a.w;
	}
}e[N];
struct qu{
	int s1,s2,id,ans;
}qt[Q];
int c,n,m,d,q;
int w[N],head[N],nxt[N],cnt=0,vis[N];
int dis[N];
bool add(int u,int v,int w){
	e[++cnt]={v,w},nxt[cnt]=head[u],head[u]=cnt;
}
bool cmp1(qu a,qu b){
	return a.s1<b.s2;
}
bool cmp2(qu a,qu b){
	return a.id<b.id;
}
void dij(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<node,vector<node>,greater<node> >q;
	dis[s]=0;
	q.push(node{s,0});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(vis[u.v]>m/2) continue;
		for(int i=head[u.v];i;i=nxt[i])
			if(dis[e[i].v]>=u.w+e[i].w){
				dis[e[i].v]=u.w+e[i].w,vis[e[i].v]++;
				q.push(node{e[i].v,dis[e[i].v]});
			}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,prea=0,pret=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			if(j>1) add(prea,x,pret+t);
			prea=x,pret=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qt[i].s1>>qt[i].s2;
		qt[i].id=i;
	}
	sort(qt+1,qt+1+q,cmp1);
	for(int i=1;i<=q;){
		dij(qt[i].s1);
		qt[i].ans+=dis[qt[i].s2],i++;
		while(qt[i].s1==qt[i-1].s2) qt[i].ans=dis[qt[i].s2],i++;
	}
	sort(qt+1,qt+1+q,cmp2);
	for(int i=1;i<=q;i++) cout<<qt[i].ans+w[qt[i].s1]+w[qt[i].s2]<<"\n";
	return 0;
}
