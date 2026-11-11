#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
int c,n,m,d,q,k,cnt,ww,u,lastv,v,idmax;
int w[N];
int t[N];
struct node{
	int nxt;
	int w;
};
struct node1{
	int id;
	int dist;
};
struct plan{
	int st;
	int ed;
};
bool cmp(node1 a,node1 b){
	return a.dist<b.dist;
}
vector<node> map1[N];
plan plan1[100005];
int vis[N];
int dist[N];

void dij(int st){
	for(int i=1;i<=cnt;i++){
		dist[i]=INT_MAX;
		vis[i]=0;
	}
	dist[0]=INT_MAX;
	dist[st]=0;
	while(1){
		int p=0;
		idmax=INT_MAX;
		//cout<<idmax<<endl;
		for(int i=1;i<=cnt;i++){
			//cout<<"dist"<<dist[i]<<endl;
			if(vis[i]){
				continue;
			}else if(dist[i]<idmax){
				p=i;
				//cout<<"p:"<<p<<endl;
				idmax=dist[i];
				//cout<<"dist[i]:"<<dist[i]<<endl;
			}
		}
		//cout<<"!!!!"<<idmax<<endl;
		if(p==0){
			return;
		}
		vis[p]=1;
		for(auto i:map1[p]){
			if(dist[p]+i.w<dist[i.nxt] and vis[i.nxt]==0){
				dist[i.nxt]=dist[p]+i.w;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cnt=m;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>u>>ww;
		v=++cnt;
		map1[u].push_back({v,ww});
		map1[v].push_back({u,ww});
		lastv=v;		
		for(int j=2;j<=k;j++){
			cin>>u>>ww;
			v=++cnt;
			map1[v].push_back({lastv,0});
			map1[lastv].push_back({v,0});
			map1[u].push_back({v,ww});
			map1[v].push_back({u,ww});
			lastv=v;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>plan1[i].st>>plan1[i].ed;
		//cout<<"st="<<plan1[i].st<<endl;
		dij(plan1[i].st);
//		for(int i=1;i<=cnt;i++){
//			cout<<dist[i]<<" ";
//		}
//		
		cout<<dist[plan1[i].ed]+w[plan1[i].st]+w[plan1[i].ed]<<"\n";
	}
	
	return 0;
}
