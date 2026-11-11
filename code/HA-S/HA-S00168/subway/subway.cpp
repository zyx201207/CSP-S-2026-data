#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
int c,n,m,d,nm;
int w[N];
int k[N],a[N][510],t[N][510];
struct node{
	int vv;
	int id;
	int ti;
};
vector<node>G[N];
int dis[N];
queue< pair<int,int> >q;
bool vis[N][510];
vector<int>p[N];
int SPFA(int s,int r){
	for(int i=0;i<p[s].size();i++){
		q.push({s,p[s][i]});
		vis[s][p[s][i]]=1;
	}
	while(!q.empty()){
		int u=q.front().first;
		int idn=q.front().second;
		q.pop();
		for(node no:G[u]){
			int v=no.vv;
			int idnx=no.id;
			int tim=no.ti;
			if(idnx!=idn){
				dis[v]+=a[u][idn]+a[u][idnx];
			}else{
				dis[v]+=0;
			}
			if(vis[v][idnx]==0){
				q.push({v,idnx});
				vis[v][idnx]=1;
			}
		}
	}
	dis[r]+=w[s]+w[r];
	return dis[r];
}
int l,r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>nm;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>a[1][i]>>t[1][i];
		p[a[1][i]].push_back(i);
		for(int j=2;j<=k[i];j++){
			cin>>a[j][i]>>t[j][i];
			G[a[j][i]].push_back({a[j-1][i],i,t[j][i]});
			G[a[j-1][i]].push_back({a[j][i],i,t[j-1][i]});
			p[a[j][i]].push_back(i);
		}
	}
	for(int i=1;i<=nm;i++){
		cin>>l>>r;
		cout<<SPFA(l,r);
	}
	return 0;
}   
