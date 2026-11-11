#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long c,n,m,d,q,w[N],a[N],t[N],sum,js,ans,x,y,z,dis[1005][1005],xt;
vector<pair<long long,long long>>e[N];
void dij(long long start){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
	q.push({start,0});
	while(!q.empty()){
		long long pos=q.top().first,wei=q.top().second;
		q.pop();
		for(pair<long long,long long>i:e[pos]){
			long long u=i.first,w=i.second;
			if(dis[start][u]>wei+w){
				dis[start][u]=wei+w;
				q.push({u,wei+w});
			}
		}
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++)
			cin>>a[j]>>t[j];
		for(int j=1;j<=x;j++)
			for(int k=j+1;k<=x;k++)
				e[a[j]].push_back({a[k],t[j]+t[k]}),e[a[k]].push_back({a[j],t[j]+t[k]});
	}
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			dis[i][j]=1e13;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(dis[x][y]==1e13)
			dij(x);
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return;
}
void solve2(){
//	vector<long long>ee[20005];
//	long long diss[20005][20005],f[20005][20005];
//	for(int i=1;i<=n;i++){
//		cin>>x;
//		for(int j=1;j<=x;j++)
//			cin>>a[j]>>t[j],xt=t[j];
//		for(int j=1;j<=x;j++)
//			for(int k=j+1;k<=x;k++)
//				ee[a[j]].push_back(a[k]),ee[a[k]].push_back(a[j]);
//		for(int i=1;i<=20000;i++)
//			for(int j=1;j<=20000;j++)
//				diss[i][j]=1e13,f[i][j]=0;
//		for(int i=1;i<=q;i++){
//			cin>>x>>y;
//			if(diss[x][y]==1e13){
//				queue<pair<long,long>>q;
//				q.push({x,0});
//				while(!q.empty()){
//					long long pos=q.front().first,wei=q.front().second;
//					q.pop();
//					if(f[x][pos])
//						continue;
//					f[x][pos]=1;
//					diss[x][pos]=wei;
//					for(long long i:ee[pos])
//						q.push({i,wei+1});
//				}
//			}
//			cout<<diss[x][y]*xt+w[x]+w[y]<<"\n";
//		}
//	}
	return;
}
void solve3(){
	return;
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	solve1();
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

15 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
