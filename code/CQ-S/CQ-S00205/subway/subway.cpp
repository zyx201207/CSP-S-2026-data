#include<bits/stdc++.h>
using namespace std;
const int N=125010;
int c,n,m,d,q,head[N],top;
int w[N],t[510][N],l[510];
struct SUBWAY{
	int v,nxt,sub;
}e[2*N];
void add(int x,int y,int w){
	e[++top].v=y;
	e[top].sub=w;
	e[top].nxt=head[x];
	head[x]=top;
}
int dis[N],vis[N];
int csps(int x,int y){
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=w[x];
	q.push({w[x],{x,0}});
	while(!q.empty()){
		int zhi=q.top().first;
		int point=q.top().second.first;
		int sub=q.top().second.second;
		q.pop();
		if(point==y){
			dis[y]+=w[y]+t[sub][y];
			break;
		}
		if(vis[point])continue;
		vis[point]=1;
		for(int i=head[point];i!=-1;i=e[i].nxt){
			int v=e[i].v;
			if(vis[v])continue;
			if(e[i].sub!=sub){
				int k=t[e[i].sub][point];
				k=k+t[sub][point];
				dis[v]=min(dis[v],zhi+k);
				q.push({dis[v],{v,e[i].sub}});
			}else{
				dis[v]=min(dis[v],zhi);
				q.push({dis[v],{v,e[i].sub}});
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int tk;cin>>tk;
			cin>>t[i][tk];
			l[j]=tk;
		}
		for(int j=1;j<k;j++){
			add(l[j],l[j+1],i);
			add(l[j+1],l[j],i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			add(i,i,j);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<csps(x,y)<<endl;
	}
}
/*
=8+4+(11)+(3)+7+2=35
*/
