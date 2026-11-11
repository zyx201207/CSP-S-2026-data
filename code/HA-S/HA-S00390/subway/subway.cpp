#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
const int M=5005;
int cnt,h[M],nxt[M],to[M],val[M],st[M];
int w[M],k[M],b[M];
int dis[M][M],dis0[M];
vector<int>vv[M];
void add(int a,int b,int c){
	to[++cnt]=b;
	st[cnt]=a;
	val[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
typedef pair<int,int> PII;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>Q;
	d+=2;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		add(i*d,i*d+1,w[i]);
		add(i*d+1,i*d,w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int num,vl;
			cin>>num>>vl;
			vv[i].push_back(num);
			add(num*d+1,num*d+(i+1),vl);
			add(num*d+(i+1),num*d+1,vl);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<vv[i].size()-1;j++){
			int u=vv[i][j],v=vv[i][j+1];
			add(u*d+(i+1),v*d+(i+1),0);
			add(v*d+(i+1),u*d+(i+1),0);
		}
	}
	int N=m*d+(n+1);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			dis[i][j]=0x3fffffff;
		}
		dis[i][i]=0;
	}
	for(int t=1;t<=N;t++){
		memset(b,0,sizeof(b));
		priority_queue<PII,vector<PII>,greater<PII> >q;
		q.push({0,t});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(b[u]==1) continue; 
			b[u]=1;
			for(int i=h[u];i;i=nxt[i]){
				int v=to[i];
				if(b[v]) continue;
				if(dis[t][v]>dis[t][u]+val[i]){
					dis[t][v]=dis[t][u]+val[i];
					q.push({dis[t][v],v});
				}
			}
		}
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x*d][y*d]<<"\n";
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

35
16



*/
