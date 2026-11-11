#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
int c,n,m,d,q;
int w[505];
struct node{
	int v,w,next;
}edge[900005];
int head[600005];
int cnt;
void add(int u,int v,int w){
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int bfs(int x,int y){
	priority_queue<PII,vector<PII>,greater<PII> > p;
	p.push({0,x});
	while(!p.empty()){
		PII k=p.top();
		p.pop();
		int d1=k.first;
		int u=k.second;
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].v;
			int w1=edge[i].w;
			if(v==y){
				return d1+w1;
			}
			p.push({d1+w1,v});
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			add(m+i,v,w);
			add(v,m+i,w);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)+w[x]+w[y]<<"\n";
	}
}
