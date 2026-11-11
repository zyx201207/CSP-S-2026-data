#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=510;
const int M=3010;
const int INF=1e9;
int c,n,m,D,q,W[M],d[M],vis[M],a[M][M];
int head[M],to[M],nxt[M],tot,w[M];
void add(int x,int y,int z){
	to[++tot]=y;
	w[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct node{
	int i,ti;
};
vector<node> t[M];
void dijk(int s){
	for(int i=0;i<=m+n;i++){
		d[i]=INF;
		vis[i]=0;
	}
	d[s]=0;
	priority_queue<PII,vector<PII>,greater<PII > > q;
	q.push({0,s});
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i],z=w[i];
			if(d[y]>d[x]+z){
				d[y]=d[x]+z;
				q.push({d[y],y});
			}
		}
	}
}
void dijks(int s){
	for(int i=0;i<=m+n;i++){
		vis[i]=0;
		a[s][i]=INF;
	}
	a[s][s]=0;
	priority_queue<PII,vector<PII>,greater<PII > > q;
	q.push({0,s});
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i],z=w[i];
			if(a[s][y]>a[s][x]+z){
				a[s][y]=a[s][x]+z;
				q.push({a[s][y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k; 
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			add(x,i+m,y);
			add(i+m,x,y);
		}
	}
	if(9<=c&&c<=11){
		for(int i=1;i<=m;i++){
			dijks(i);
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<a[x][y]+W[x]+W[y]<<"\n";
		}
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dijk(x);
		cout<<d[y]+W[x]+W[y]<<"\n";
	}
	return 0;
}
