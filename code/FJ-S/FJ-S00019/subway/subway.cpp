#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long c,n,m,d,q,w[N],t[510][N],dis[N][N],pd[N][N],line[N][510],sum[N];
vector<int> g[N];
bool vis[N][N];
struct node{
	long long le;
	long long e;
};
void bfs(long long s){
	queue<node> q;
	node t;
	t.le=w[s];
	t.e=s;
	q.push(t);
	while(!q.empty()){
		node u=q.front();
		q.pop();
		for(int i=0;i<g[u.e].size();i++){
			int v=g[u.e][i];
			if(!vis[s][v]){
				node tmp;
				tmp.e=v;
				tmp.le=dis[s][u.e]-w[u.e]+w[v]+t[pd[v][u.e]][u.e]+t[pd[v][u.e]][v];
				q.push({tmp});
				dis[s][v]=dis[s][u.e]-w[u.e]+w[v]+t[pd[v][u.e]][u.e]+t[pd[v][u.e]][v];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		dis[i][i]=0;
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			sum[x]++;
			for(int l=1;l<=m;l++){
				if(line[l][i]&&l!=i){
					pd[l][x]=i;
					pd[x][l]=i;
				}
			}
			line[x][i]=1;
			t[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		if(st>ed)swap(st,ed);
		if(pd[st][ed]!=0)cout<<w[st]+w[ed]+t[pd[st][ed]][st]+t[pd[st][ed]][ed];
		else{
			if(dis[st][ed]){
				cout<<dis[st][ed]<<endl;
				continue;
			}
			bfs(st);
			cout<<dis[st][ed]<<endl;
		}
	}
	return 0;
}

