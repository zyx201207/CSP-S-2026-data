#include<bits/stdc++.h>
using namespace std;

struct Dt{
	int x;
	long long dis;
};

struct qus{
	int x,y,idx;
};

bool operator<(Dt lhs,Dt rhs){
	return lhs.dis>rhs.dis;
}

bool cmp(qus a,qus b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int c,n,m,d,q;
int w[500010];
bool vis[500510];
long long dis[500510];
long long ans[100010];
qus tmp[100010];
vector<pair<int,long long> > edge[1000010]; 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			edge[a].push_back({m+i,t});
			edge[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>tmp[i].x>>tmp[i].y;
		tmp[i].idx=i;
	}
	sort(tmp+1,tmp+1+q,cmp);
	priority_queue<Dt> heap;
	for(int qqq=1;qqq<=q;qqq++){
		int x=tmp[qqq].x,y=tmp[qqq].y;
		if(qqq!=1&&x==tmp[qqq-1].x){
			ans[tmp[qqq].idx]=0LL+w[x]+w[y]+dis[y];
			continue;
		}
		int s=x;
		memset(dis,0x3F,sizeof(dis));
		memset(vis,false,sizeof(vis));
		heap.push({s,0});
		dis[s]=0;
		while(!heap.empty()){
			int u=heap.top().x;
			heap.pop();
			if(vis[u]) continue;
			vis[u]=true;
			for(int i=0;i<edge[u].size();i++){
				int v=edge[u][i].first;
				long long w=edge[u][i].second;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					heap.push({v,dis[v]});
				}
			}
		}
		ans[tmp[qqq].idx]=0LL+w[x]+w[y]+dis[y];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
