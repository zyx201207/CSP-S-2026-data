#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pa;
const int MX=5*1e6+50; 
struct E{
	int to;
	int next;
	int w;
}e[MX]; 
int tot=1;
int head[MX];
ll dis[MX];
int c,n,m,d,q;
int x_cnt=0;
bool vis[MX];
void add(int u,int v,int w){
	e[tot].to=v;
	e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot++;
}
void csh(){
    for(int i=0;i<=m*(n+1);i++){
    	dis[i]=1234567890;
	}
	memset(vis,0,sizeof(vis));
}
void dijstra(int s){
	csh();
	priority_queue<pa,vector<pa>,greater<pa> > q;
	dis[s]=0;
	pa d(0,s);
	q.push(d);
	while(!q.empty()){
		ll jd=q.top().second;
		q.pop();
		if(vis[jd]==1)continue;
		vis[jd]=1;
		for(int i=head[jd];i!=-1;i=e[i].next){
			int v=e[i].to;
			int w=e[i].w;
			if(dis[v]>dis[jd]+w){
				dis[v]=dis[jd]+w;
				if(vis[v]!=1){
					pa d1(dis[v],v);
					q.push(d1);
				}
			}
		}
	}
}
int v_cnt=0;
int wz[MX];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>wz[i];
	}
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v;
			int t;
			cin>>v>>t;
			add(v,i*m+v,t);
			add(i*m+v,v,t);
			if(j>1){
				add(i*m+v,i*m+v_cnt,0);
				add(i*m+v_cnt,i*m+v,0);
			}
			v_cnt=v;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		int cnt=0;
		cin>>x>>y;
		cnt+=wz[x];
		cnt+=wz[y];
		if(x_cnt!=x)dijstra(x);
		x_cnt=x;
		cnt+=dis[y];
		cout<<cnt<<endl;
	}
	return 0;
}
