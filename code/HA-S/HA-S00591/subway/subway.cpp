#include<bits/stdc++.h>
using namespace std;
//#define pair<int,int> pii

const int M=250000,N=2e6;
struct node{
	int to,nxt,val;
}e[N];
int h[N],cnt=0;
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
int c,n,m,d,ques;
int w[M];
int k[510];
int a[510][510],t[510][510];

int dis[N];
priority_queue < pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > q;
void dij(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while(q.size()){
		int u=q.top().second;
		int t=q.top().first;
		q.pop();
		if(dis[u]!=t){
			continue;
		}
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v]=dis[u]+e[i].val;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0); 
	cin>>c>>n>>m>>d>>ques;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				int u=a[i][j],v=a[i][l];
				int w=t[i][j]+t[i][l];
				add(u,v,w);
				add(v,u,w);				
			}

		}
	}
	int x,y;
	for(int i=1;i<=ques;i++){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
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
32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



*/
