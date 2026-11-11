#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q1;
int ktz[1005];
struct node{
	int id,idtz; 
};
struct node1{
	int v,w;
};
struct node2{
	int nowid,val;
};
struct node3{
	int biao,minnum;
};
bool operator<(node3 a,node3 b){
	return a.minnum>b.minnum;
} 
vector<node>xian[505];
vector<node1>g[550005];
vector<node2>zhan[505];
int k[550005],ans[1005][1005];
bool f[550005];
priority_queue<node3>q;
void dij(int s){
	memset(k,0x3f,sizeof(k));
	memset(f,0,sizeof(f)); 
	k[s]=0;q.push({s,0});
	while(!q.empty()){
		int biao=q.top().biao;
		q.pop();
		if(f[biao]==1)continue;
		f[biao]=1;
		for(int i=0;i<g[biao].size();i++){
			int v=g[biao][i].v,w=g[biao][i].w;
			if(k[v]>k[biao]+w){
				k[v]=k[biao]+w;
				q.push({v,k[v]}); 
			}
		}
	}
	for(int i=1;i<=m;i++)ans[s][i]=k[i];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)cin>>ktz[i];
	for(int i=1;i<=n;i++){
		int ki;cin>>ki;
		for(int j=1;j<=ki;j++){
			int id,idtz;
			cin>>id>>idtz;
			xian[i].push_back({id,idtz});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<xian[i].size();j++){
			if(j>0){
				g[xian[i][j].id+i*m].push_back({xian[i][j-1].id+i*m,0});
				g[xian[i][j-1].id+i*m].push_back({xian[i][j].id+i*m,0});
			}
			g[xian[i][j].id+i*m].push_back({xian[i][j].id,ktz[xian[i][j].id]+xian[i][j].idtz});
			g[xian[i][j].id].push_back({xian[i][j].id+i*m,ktz[xian[i][j].id]+xian[i][j].idtz});
			zhan[xian[i][j].id].push_back({xian[i][j].id+i*m,xian[i][j].idtz});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<zhan[i].size();j++){
			for(int k=j+1;k<zhan[i].size();k++){
				g[zhan[i][j].nowid].push_back({zhan[i][k].nowid,zhan[i][j].val+zhan[i][k].val});
				g[zhan[i][k].nowid].push_back({zhan[i][j].nowid,zhan[i][j].val+zhan[i][k].val});
			} 
		} 
	}
	for(int i=1;i<=m;i++)dij(i);
	while(q1--){
		int s,t;
		cin>>s>>t;
		cout<<ans[s][t]<<"\n"; 
	}
	return 0;
}
