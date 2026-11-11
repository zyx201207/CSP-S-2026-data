#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int s[N],t[N];
struct edge{
	int to,nxt,dis;
}e[N];
int cnt,head[N],dis[N];
bool vis[N];
void add(int u,int v,int w){
	cnt++;
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
struct node{
	int dis,pos;
	bool operator<(const node &x)const{
		return x.dis<dis;
	}
};
priority_queue<node> q;
void dijkstra(int s){
	while(!q.empty()){
		q.pop();
	}
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push((node){0,s});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].dis){
				dis[y]=dis[x]+e[i].dis;
				q.push((node){dis[y],y});
			}
		}
	}
	memset(vis,0,sizeof(vis));
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		add(i,i+i*10,w);
		add(i+i*10,i,w);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[j]>>t[j];
		}
		for(int j=1;j<k;j++){
			add(s[j]+s[j]*10,s[j]+s[j]*10+s[j]*100,t[j]);
			add(s[j]+s[j]*10+s[j]*100,s[j]+s[j]*10,t[j]);
			add(s[j+1]+s[j+1]*10+s[j+1]*100,s[j]+s[j]*10+s[j]*100,0);
			add(s[j]+s[j]*10+s[j]*100,s[j+1]+s[j+1]*10+s[j+1]*100,0);
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		dijkstra(l);
		cout<<dis[r]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
