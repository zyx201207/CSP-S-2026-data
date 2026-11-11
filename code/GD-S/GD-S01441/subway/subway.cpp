#include <bits/stdc++.h>
using namespace std;
const long long MAXN=505;//线路数 
const long long MAXM=2e4+5;//结点数 
long long w[MAXM];
long long k[MAXN];
long long a[MAXN][25];
long long t[MAXN][25];
long long dis[MAXM][MAXN];
struct node{
	long long v,line,ti,nxt_ti;
};
vector<node> g[MAXM];
struct node1{
	long long v,line,ti,nxt_ti;
	long long sum;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(long long j=0;j<k[i];j++){
			long long tmp=j+1;
			if(j==k[i]-1) tmp=0;
			g[a[i][tmp]].push_back({a[i][j],i,t[i][tmp],t[i][j]});
			g[a[i][j]].push_back({a[i][tmp],i,t[i][j],t[i][tmp]}); 
		}
	}
	while(Q--){
		long long st,en;
		cin>>st>>en;
		long long ans=w[st]+w[en];
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=n;j++){
				dis[i][j]=1e18;
			}
		}
		queue<node1> q;
		for(long long i=0;i<g[st].size();i++){
			q.push({g[st][i].v,g[st][i].line,g[st][i].ti,g[st][i].nxt_ti,g[st][i].ti});
		}
		long long mi=9e18;
		while(!q.empty()){
			long long u=q.front().v;
			long long line=q.front().line;
			long long ti=q.front().ti;
			long long nxt_ti=q.front().nxt_ti;
			long long sum=q.front().sum;
			q.pop();
			if(u==en){
				mi=min(mi,sum+nxt_ti);
//				cout<<u<<" "<<line<<" "<<ti<<" "<<nxt_ti<<" "<<sum<<" "<<mi<<'\n';
			}
			for(auto v:g[u]){
				if(v.line!=line){
					if(dis[v.v][v.line]>sum+nxt_ti+v.ti){
						dis[v.v][v.line]=sum+nxt_ti+v.ti;
						q.push({v.v,v.line,v.ti,v.nxt_ti,dis[v.v][v.line]});
					}
				}else{
					if(dis[v.v][line]>sum){
						dis[v.v][line]=sum;
						q.push({v.v,v.line,v.ti,v.nxt_ti,sum});
					}
				}
			}
		}
		cout<<mi+ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<g[i].size();j++){
			cout<<i<<" "<<j<<" "<<g[i][j].v<<" "<<g[i][j].line<<" "<<g[i][j].ti<<"\n";
		}
	}
			queue<node1> q1=q;
			long long ct=0;
			while(!q1.empty()){
				cout<<"In range "<<++ct<<"\n";
				auto [u,line,ti,nxt_ti,sum]=q1.front();q1.pop();
				cout<<u<<" "<<line<<" "<<ti<<" "<<nxt_ti<<" "<<sum<<"\n";
			}


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
