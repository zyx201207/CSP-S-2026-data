#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define ll long long
#define pa pair<ll,int>
using namespace std;
const int C=25+5,N=505,M=5e5+5,K=5e5+5,SK=5e5+5,D=20+5,Q=1e5+5,A=5e5+5;
const ll W=1e9+5,T=1e9+5;
int c,n,m,d,qq,kk,a,x,y;
ll w[M],t,s[N][N],dis[N+M],ans,num;
vector<pair<int,ll>>q[N+M];
void dij(int rt){
	priority_queue<pa>Q;
	dis[rt]=0;
	Q.push({0,rt});
	while(!Q.empty()){
		int u=Q.top().second;
		Q.pop();
		for(auto i:q[u]){
			int v=i.first;ll vt=i.second;
			if(dis[v]>dis[u]+vt){
				dis[v]=dis[u]+vt;
				Q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i+=1){
		cin>>w[i];
	}
	for(int i=1;i<=n;i+=1){
		cin>>kk;
		for(int j=1;j<=kk;j+=1){
			cin>>a>>t;
			q[i].push_back({n+a,t});
			q[n+a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i+=1){
		for(int j=1;j<=n;j+=1){
			s[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	if(n*m>=1000000){
		for(int i=n+1;i<=n+m;i++){
			for(auto j:q[i]){
				int u=j.first;ll ut=j.second;
				for(auto k:q[i]){
					int v=k.first;ll vt=k.second;
					if(u==v)s[u][v]=0;
					else s[u][v]=s[v][u]=min(s[u][v],ut+vt);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
				}
			}
		}
	}else{
		for(int i=1;i<=n;i+=1){
			for(int j=1;j<=n+m;j+=1)dis[j]=0x3f3f3f3f3f3f3f3f;
			dij(i);
			for(int j=1;j<=n;j+=1)s[i][j]=dis[j];
		}
	}
	while(qq--){
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f,num=w[x]+w[y];
		x+=n,y+=n;
		for(auto i:q[x]){
			int u=i.first;ll ut=i.second;
			for(auto j:q[y]){
				int v=j.first;ll vt=j.second;
				ans=min(ans,num+ut+vt+s[u][v]);
			}
		}
		cout<<ans<<endl;
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
