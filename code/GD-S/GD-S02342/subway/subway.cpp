#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N=5e5+10,M=1e7+10,K=25,INF=0x3f3f3f3f;
const int NN=1e4+10;
int n,m,c,d,q;
LL cnt,cost[N];
LL e[M],ne[M],h[M],idx,w[M];
void add(LL a,LL b,LL c){
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
LL ans[NN][NN];
LL dist[M];
LL dijkstra(LL start,LL end){
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,start});
	if(start<NN&&ans[start][0]==-1) return ans[start][end];
	memset(dist,0x3f,sizeof dist);
	dist[start]=0;
	while(heap.size()){
		auto t=heap.top();
		heap.pop();
		LL d=t.x;
		LL val=t.y;
		if(d>dist[val]) continue;
		for(LL i=h[val];~i;i=ne[i]){
			LL j=e[i];
			//cout<<"从"<<val<<"走到"<<j<<"的路径("<<w[i]<<")\n"; 
			if(dist[j]>dist[val]+w[i])
			{
				dist[j]=dist[val]+w[i];
				heap.push({dist[j],j});
			}
		}
	}
	if(start<NN)
		for(int i=1;i<=n;i++) ans[start][i]=dist[i];
	if(start<NN) ans[start][0]=-1;
	return dist[end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(h,-1,sizeof h);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>cost[i];
	cnt=n;
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		vector<LL> expend;
		for(int j=1;j<=k;j++){
			int x;
			LL t;
			cin>>x>>t;
			add(x,++cnt,t);
			add(cnt,x,t);
			//cout<<x<<" & "<<cnt<<"("<<t<<")\n";
			expend.push_back(cnt);
		}
		for(int j=1;j<expend.size();j++){
			add(expend[j-1],expend[j],0);
			add(expend[j],expend[j-1],0);
			//cout<<expend[j]<<" & "<<expend[j-1]<<"("<<0<<")\n";
		}
	}
	while(q--){
		LL start,end;
		cin>>start>>end;
		LL spend=cost[start]+cost[end];
		LL ans=dijkstra(start,end);
		cout<<ans+spend<<endl;
	}
	return 0;
}
