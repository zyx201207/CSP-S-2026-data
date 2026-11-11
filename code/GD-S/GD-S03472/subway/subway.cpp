#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=2e4+5;
int c,n,m,d,q,arr[N][N],dist[N],start[N];
pair<int,int> a[N];
vector<int>G[N];

void dijkstra(int x){
	dist[x]=0;
	memset(dist,0x3f,sizeof(dist));
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().second,val=pq.top().first;
		pq.pop();
		if(val>dist[u])
			continue;
		for(int v:G[u]){
			if(arr[min(v,u)][max(v,u)]+val<dist[v]){
				dist[v]=arr[min(v,u)][max(v,u)]+val;
				pq.push({dist[v],v});
			}
		}
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(arr,0x3f,sizeof(arr));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>start[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j].first>>a[j].second; 
		}
		for(int p1=1;p1<k;p1++){
			for(int p2=p1+1;p2<=k;p2++){
				if(arr[min(a[p1].first,a[p2].first)][max(a[p1].first,a[p2].first)]>a[p1].second+a[p2].second){
					arr[min(a[p1].first,a[p2].first)][max(a[p1].first,a[p2].first)]=a[p1].second+a[p2].second;
				}
				G[a[p1].first].push_back(a[p2].first);
				G[a[p2].first].push_back(a[p1].first);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<start[x]+start[y]+dist[y]<<endl;
	}
	return 0;
}
