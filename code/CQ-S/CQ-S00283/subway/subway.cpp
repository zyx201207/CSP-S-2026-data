#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace T2{
	const int MAXN=2e4+5;
	const int MAXM=5e2+5;
	int O,N,M,D,Q;
	int w[MAXN];
	int k[MAXM];
	int a[MAXM][MAXN];
	int t[MAXM][MAXN];
	int ti[MAXN][MAXM];
	bool vis[MAXN][MAXM];
	vector<int>G[MAXN];
	inline int Dijkstra(int start,int end){
		int Ans=1e18;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j){
				vis[i][j]=0;
			}
		}
		priority_queue<tuple<int,int,int>,
						vector<tuple<int,int,int> >,
						greater<tuple<int,int,int> > >q;
		for(int i=0;i<G[start].size();++i){
			int line=G[start][i]; 
			q.emplace(w[start]+w[end]+ti[start][line],start,line);
		}
		while(!q.empty()){
			int wz=get<0>(q.top());
			int u=get<1>(q.top());
			int l=get<2>(q.top());q.pop();
			if(u==end){
				Ans=min(Ans,wz+ti[u][l]);
				continue;
			}
			if(vis[u][l])continue;vis[u][l]=1;
			for(int i=1;i<=k[l];++i){
				int v=a[l][i];
				if(!vis[v][l])q.emplace(wz,v,l);
			}
			for(int i=0;i<G[u].size();++i){
				int nl=G[u][i];
				if(nl==l)continue;
				if(!vis[u][nl])q.emplace(wz+ti[u][l]+ti[u][nl],u,nl);
			}
		}
		if(Ans==1e18)return -1;
		return Ans;
	}
	signed main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>O>>M>>N>>D>>Q;
		for(int i=1;i<=N;++i)cin>>w[i];
		for(int i=1;i<=M;++i){
			cin>>k[i];
			for(int j=1;j<=k[i];++j){
				cin>>a[i][j]>>t[i][j];
			}
		}
		for(int i=1;i<=M;++i){
			for(int j=1;j<=k[i];++j){
				ti[a[i][j]][i]=t[i][j];
			}
		}
		for(int i=1;i<=M;++i){
			for(int j=1;j<=k[i];++j){
				G[a[i][j]].emplace_back(i);
			}
		}
		while(Q--){
			int u,v;cin>>u>>v;
			cout<<Dijkstra(u,v)<<"\n";
		}
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	T2::main();
	return 0;
}
//内存：248392KB
//时间：O(QNM)
//预估分数：? 
