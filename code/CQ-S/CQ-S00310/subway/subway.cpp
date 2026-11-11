#include <bits/stdc++.h>
using namespace std;
int n,m,d,q,k,u,use[600010];
long long v,a[500010],dd[610][610],dis[600010];
vector<pair<int,long long> > e[600010],go[500010];
struct no{
	int id;
	long long x;
};
bool operator<(no aa,no bb){
	return aa.x>bb.x;
}
void dij(int st){
	for(int i=1;i<=n+m;i++) dis[i]=1e18,use[i]=0;
	priority_queue<no> pq;
	dis[st]=0,pq.push({st,0});
	while(!pq.empty()){
		int id=pq.top().id;
		long long x=pq.top().x;
		pq.pop();
		if(use[id]) continue;
		use[id]=1;
		for(int i=0;i<e[id].size();i++){
			int to=e[id][i].first;
			long long w=e[id][i].second;
			if(dis[to]>x+w) dis[to]=x+w,pq.push({to,dis[to]});
		}
	}
	return ;
}
//我要成为赌徒，CCF卡不了SPFA
void spfa(int st,bool fl){
	queue<int> q;
	for(int i=1;i<=n+m;i++) dis[i]=1e18,use[i]=0;
	q.push(st),use[st]=1,dis[st]=0;
	while(!q.empty()){
		int id=q.front();
		use[id]=0,q.pop();
		for(int i=0;i<e[id].size();i++){
			int to=e[id][i].first;
			long long x=e[id][i].second;
			if(fl){
				if(dis[to]==1e18){
					dis[to]=dis[id]+x;
					q.push(to),use[to]=1;
				}
				continue;
			}
			if(dis[to]>dis[id]+x){
				dis[to]=dis[id]+x;
				if(!use[to]) q.push(to),use[to]=1;
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	long long sum_k=0,lo=-1e18;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>k;
		sum_k+=k;
		while(k--){
			cin>>u>>v;
			if(lo==-1e18) lo=v;
			else{
				if(lo!=v) fl=0;
			}
			go[u].push_back({i,v}),e[m+i].push_back({u,v}),e[u].push_back({m+i,v});
		}
	}
//	cout<<n<<" "<<m<<" "<<d<<" "<<q<<" "<<sum_k<<" "<<n<<endl;
	long long kkk=log2(sum_k);
//	cout<<kkk<<endl;
	for(int i=1;i<=n;i++){
//		cout<<sum_k*kkk*n<<endl;
		if(sum_k*kkk*(n*1LL)<5e7) dij(m+i);
		else spfa(m+i,fl);
		for(int j=1;j<=n;j++) dd[i][j]=dis[m+j];
//		for(int j=1;j<=n+m;j++) cout<<dis[j]<<" ";
//		cout<<endl;
	}
	while(q--){
		cin>>u>>v;
		long long ans=1e18;
		for(int i=0;i<go[u].size();i++){
			for(int j=0;j<go[v].size();j++) ans=min(ans,dd[go[u][i].first][go[v][j].first]+go[u][i].second+go[v][j].second);
		}
		cout<<ans+a[u]+a[v]<<'\n';
	}
	return 0;
}
/*
fc subway.out subway1.ans
考虑虚点建图
dij不要全部点，时间大
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

算了，既然dij过不去
赌徒行为：用SPFA 
*/
