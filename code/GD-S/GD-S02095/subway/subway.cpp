#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piu pair< int,unsigned int>
int c,n,m,d,q1;
int w[500001],a,t;
vector<piu> tree[500001];
vector<pii> tu[501];
set<int>line[501];
unsigned int mini[501];
int u,v;
int b[501];
unsigned int anss[501];
void bfs(){
	long long ans=LLONG_MAX;
	priority_queue<pair<long long,int>> q;
	for(pii x:tree[u])
		q.push({w[u]+x.second,x.first});
	b[u]=w[u];
	while(q.size()){
		pii y=q.top();q.pop();
		int x=y.second;
		long long time=y.first;
		if(line[x].count(v)==1){
			ans=min(ans,time+w[v]+anss[x]);
		} 
		for(pii to:tu[x]){
			if(b[to.first]==1) continue;
			else{
				b[to.first]=1;
				q.push({time+to.second,to.first});
			} 
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		memset(mini,0x3f3f3f3f,sizeof(mini));
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			for(piu x:tree[a]){
				mini[x.first]=min(mini[x.first],t+x.second);
			}
			tree[a].push_back({i,t});
			line[i].insert(a);
		}
		for(int j=1;j<i;j++)
			tu[j].push_back({i,mini[j]}),tu[i].push_back({j,mini[j]});
	}
	for(int i=1;i<=q1;i++){
		memset(b,0,sizeof(b));long long ans=0;
		cin>>u>>v;
		for(piu x:tree[v]) anss[x.first]=x.second;
 		bfs();
	}
		
	return 0;
}
