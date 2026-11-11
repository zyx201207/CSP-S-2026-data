#include<bits/stdc++.h>
using namespace std;
struct edges{
	int to,wt;
	edges(int TO,int WT):to(TO),wt(WT){}
};
struct nodes{
	int id;
	long long dis;
	bool operator<(const nodes other)const{
		return dis>other.dis;
	}
	nodes(int ID,long long DIS):id(ID),dis(DIS){}
};
int c,n,m,d,q,num;
vector<edges>adj[1500505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		long long w;
		cin>>w;
		adj[i].emplace_back(i+m,w);
		adj[i+m].emplace_back(i,w);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			num++;
			adj[m+a].emplace_back(2*m+n+num,t);
			adj[2*m+n+num].emplace_back(m+a,t);
			adj[2*m+i].emplace_back(2*m+n+num,0);
			adj[2*m+n+num].emplace_back(2*m+i,0);
		}
	}
	while(q--){
		int x,y,vis[1500505];
		long long tdis[1500505];
		priority_queue<nodes>pq;
		memset(vis,0,sizeof(vis));
		memset(tdis,0x3f,sizeof(tdis));
		cin>>x>>y;
		tdis[x]=0;
		pq.emplace(x,0);
		while(!pq.empty()){
			nodes be=pq.top();
			pq.pop();
			if(be.id==y){
				cout<<be.dis<<'\n';
				break;
			}
			if(vis[be.id]){
				continue;
			}
			vis[be.id]=1;
			for(auto i:adj[be.id]){
				if(tdis[i.to]>tdis[be.id]+i.wt){
					tdis[i.to]=tdis[be.id]+i.wt;
					pq.emplace(i.to,tdis[i.to]);
				}
			}
		}
	}
	return 0;
}
