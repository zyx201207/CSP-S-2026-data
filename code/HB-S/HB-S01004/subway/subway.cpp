#include<bits/stdc++.h>
using namespace std;
int t1[505],q1[505],mb[505],dis[505];
bool vis[505];
struct node{
	int t,v;
}t2[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t1[i];
	for(int i=1;i<=n;i++){
		int asd;
		cin>>asd;
		mb[i]=asd;
		for(int j=1;j<=asd;j++){
			int r,t3;
			cin>>r>>t3;
			t2[i][j].v=r;
			t2[i][j].t=t1[i]+t3;
		}
	}
	while(q--){
		memset(dis,0x3f,sizeof(dis));
		int l,r;
		cin>>l>>r;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>e;
		e.push({0,l});
		dis[l]=0;
		while(!e.empty()){
			int u=e.top().second;
			e.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=1;i<=mb[u];i++){
				int v1=t2[u][i].v;
				int w=t2[u][i].t;
				if(dis[u]+w<dis[v1]){
					dis[v1]=dis[u]+w;
					e.push({dis[v1],v1});
				}
			}
		}
		cout<<dis[r]+t2[l][l].t<<'\n';
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

