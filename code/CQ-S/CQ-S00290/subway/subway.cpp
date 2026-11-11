#include <bits/stdc++.h>
using namespace std;
int cc,dd,n,m,ti;
int w[500005];
int kk[500005];
vector<pair<int,int>>ll[1000006];
struct ul{
	int u;
	long long l;
	bool operator<(const ul o)const{
		return o.l<l;
	}
};
priority_queue<ul>pq;
//void out(){
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<setw(4)<<mp[i][j];
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//}
bitset<1000006>f;
int bfs(int x,int y){
	f=0;
	pq.push({x,0});
	while(!pq.empty()){
		int u=pq.top().u;
		int l=pq.top().l;
		pq.pop();
//		cout<<u<<' '<<x<<endl;
//		out();
		if(f[u])continue;
		if(u==y)return l;
		f[u]=1;
		for(pair<int,int> v:ll[u]){
			if(!f[v.first]){
				pq.push({v.first,l+v.second});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>cc>>m>>n>>dd>>ti;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	for(int i=1;i<=m;++i){
		cin>>kk[i];
//		if(kk[i]==1)continue;
		for(int j=1;j<=kk[i];++j){
			int a,t;
			cin>>a>>t;
			ll[a+1000].push_back({i,t});
			ll[i].push_back({a+1000,t});
		}
	}
	while(ti--){
		int a,b;
		cin>>a>>b;
		cout<<w[a]+w[b]+bfs(a+1000,b+1000)<<endl;
		
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

