#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=1e4+5;
const int INF=1e18;
int w[M];
struct node{
	int k,a[M],t[M];
}val[N];

struct sub{
	int v,w;
};
vector<sub>g[M];

bool vis[M];
int dis[M][M];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	//c=read();
	//n=read();
	//m=read();
	//d=read();
	//q=read();
	for(int i=1;i<=m;i++){
		cin>>w[i];
		//w[i]=read();
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=INF;
		}
	}
	
	for(int i=1;i<=n;i++){
		cin>>val[i].k;
		//val[i].k=read();
		for(int j=1;j<=val[i].k;j++){
			//val[i].a[j]=read();
			//val[i].t[j]=read();
			cin>>val[i].a[j]>>val[i].t[j];
		}
		for(int j=1;j<=val[i].k;j++){
			for(int z=j+1;z<=val[i].k;z++){
				int w=val[i].t[j]+val[i].t[z];
				dis[val[i].a[z]][val[i].a[j]]=dis[val[i].a[j]][val[i].a[z]]=min(w,dis[val[i].a[j]][val[i].a[z]]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(k==i)continue;
			for(int j=i+1;j<=m;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j])
				dis[i][j]=dis[i][k]+dis[k][j]; 
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		cin>>val[i].k;
		for(int j=1;j<=val[i].k;j++)cin>>val[i].a[j]>>val[i].t[j];
		for(int j=1;j<=val[i].k;j++){
			for(int z=j+1;z<=val[i].k;z++){
				int w=val[i].t[j]+val[i].t[z];
				g[val[i].a[z]].push_back({val[i].a[j],w});
				g[val[i].a[j]].push_back({val[i].a[z],w});
				dis[val[i].a[z]][val[i].a[j]]=dis[val[i].a[j]][val[i].a[z]]=w;
			}
		}
	}

	for(int i=1;i<=m;i++){
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>dq;
		dq.push(make_pair(0,i));
		memset(vis,0,sizeof(vis));
		while(!dq.empty()){
			pair<int,int>tmp=dq.top();
			dq.pop();
			int d=tmp.first;
			int u=tmp.second;
			if(vis[u])continue;
			vis[u]=1;
			for(int kk=0;kk<g[u].size();kk++){
				sub e=g[u][kk];
				int w=e.w;
				int v=e.v;
				cout<<1;
				if(dis[kk][v]>dis[kk][u]+w){
					dis[kk][v]=dis[kk][u]+w;
					dq.push(make_pair(dis[kk][v],v));
				}
			}
		}
	}
	*/
	
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<'\n';
	}
	*/
	while(q--){
		int l,r;
		cin>>l>>r;
		//l=read();
		//r=read();
		if(l>r)swap(l,r);
		cout<<dis[l][r]+w[l]+w[r]<<'\n';
		//write(dis[l][r]+w[l]+w[r]);
		//putchar('\n');
	}
	return 0;
} 
