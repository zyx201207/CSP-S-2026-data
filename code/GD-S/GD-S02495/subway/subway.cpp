#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int c,n,m,d,q,dis[500005],w2[500005],k[505],vis[500005];
vector<int> a[505],t[505];
struct node{
	int v,w;
};
vector<node> e[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w2[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int a2,t2;
			cin>>a2>>t2;
			a[i].push_back(a2);
			t[i].push_back(t2);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(j==l) continue;
				e[a[i][j]].push_back((node){a[i][l],t[i][j]+t[i][l]});
			}
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			cout<<i<<" "<<e[i][j].v<<" "<<e[i][j].w<<endl;
		}
	}
	exit(0);*/
	while(q--){
		int u,v;
		cin>>u>>v;
		for(int i=1;i<=m;i++){
			if(i==u) dis[i]=0;
			else dis[i]=1e18;
			vis[i]=0;
		}
		queue<int> q2;
		while(q2.size()>0) q2.pop();
		q2.push(u);
		vis[u]=1;
		while(q2.size()>0){
			int s=q2.front();
			q2.pop();
			vis[s]=0;
			for(int i=0;i<e[s].size();i++){
				if(dis[s]+e[s][i].w<dis[e[s][i].v]){
					dis[e[s][i].v]=dis[s]+e[s][i].w;
					if(vis[e[s][i].v]==0){
						q2.push(e[s][i].v);
						vis[e[s][i].v]=1;
					}
				}
			}
		}
		cout<<dis[v]+w2[v]+w2[u]<<endl;
	}
	return 0;
}
