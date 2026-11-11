#include <bits/stdc++.h>
using namespace std;
int c,xl,n,d,p,s,z,k;
int T[500010];
int t[500010];
int U[500010];
int vv[5010][5010],v[500010];
long long dis[500010];
vector<pair<int,int> > g[500010];
void dij(int s){
	priority_queue<pair<long long,int>> q;
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++)dis[i]=LONG_LONG_MAX;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(v[u]==1)continue;
		v[u]=1;
		for(int i=0;i<g[u].size();i++){
			int vx=g[u][i].first;
			int w=g[u][i].second;
			if(dis[vx]>dis[u]+w){
				dis[vx]=dis[u]+w;
				q.push({-dis[vx],vx});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>xl>>n>>d>>p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vv[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>T[i];
	}
	while(xl--){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>U[j]>>t[j];
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				if(vv[U[i]][U[j]]!=-1){
					int sss=vv[U[i]][U[j]];
					if(t[i]+t[j]<g[U[i]][sss].second)g[U[i]][sss].second=t[i]+t[j];
				}
				else {
					g[U[i]].push_back({U[j],t[i]+t[j]});
					int kk=g[U[i]].size();
					vv[U[i]][U[j]]=kk-1;
				}
				if(vv[U[j]][U[i]]!=-1){
					int sss=vv[U[j]][U[i]];
					if(t[i]+t[j]<g[U[j]][sss].second)g[U[j]][sss].second=t[i]+t[j];
				}
				else {
					g[U[j]].push_back({U[i],t[i]+t[j]});
					int kk=g[U[j]].size();
					vv[U[j]][U[i]]=kk-1;
				}
			}
		}
	}
	for(int i=1;i<=p;i++){
		cin>>s>>z;
		dij(s);
		cout<<dis[z]+T[s]+T[z]<<endl;
	}
}
