#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,b,e;  
ll zhan[500005];
ll tai[500005];
vector<pair<int,int> > g[50005];
int dist[50005];
void dij(int begin){
bool vis[m];
	priority_queue< pair<int , int>, vector<pair< int,int> >,greater< > > q;
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	dist[begin]=0;
	q.push({0,begin});
	while(!q.empty()){
		auto m=q.top();
		q.pop();
		int k=m.second;
		if(vis[k]==1) continue;
		vis[k]=1;
		for(auto v:g[k]){
			int dian=v.first;
			int value=v.second;
			if(dist[dian]>dist[k]+value){
			dist[dian]=dist[k]+value;
				q.push({dist[dian],dian});
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 freopen("subway.in","r",stdin);
 freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tai[i];
	}
		for(int i=1;i<=n;i++) {
		int shu=0;
		cin>>shu;
		int t=shu*2;
		for(int j=1;j<=t;j++){
			cin>>zhan[j];
		}
		for(int j=1;j<=t;j++){
			if(j%2!=0){
				g[zhan[j]].push_back({i+m,zhan[j+1]});
				g[i+m].push_back({zhan[j],zhan[j+1]});
			}
		}
			memset(zhan,0,sizeof(zhan));
	}
	for(int i=1;i<=q;i++){
		int b,e;
		cin>>b>>e;
		dij(b);
		cout<<dist[e]+tai[b]+tai[e]<<endl;
	}
	return 0;
} 
