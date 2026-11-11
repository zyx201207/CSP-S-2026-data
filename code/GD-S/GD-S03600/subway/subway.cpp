#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
#define _for1(i,x,y,z) for(int i=x;i>=y;i-=z)
typedef long long ll;
const int N=5e5+15;
int c,n,m,d,q;
vector<int> sub[505];
vector<pair<pair<int,int>,int>> a[N];
ll dis[N];
bool vis[N];
void f1(int start){
	dis[start]=sub[0][start];
	priority_queue<
	pair<pair<ll,ll>,ll>,
	vector<pair<pair<ll,ll>,ll>>,
	greater<pair<pair<ll,ll>,ll>>> q;
	q.push({{(ll)sub[0][start],(ll)start},(ll)0});
	while(!q.empty()){
		int u=q.top().first.second,U=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		int sz=a[u].size()-1;
		_for(i,0,sz,1){
			int SS=0,w=a[u][i].first.second,v=a[u][i].first.first;
			int W=a[u][i].second;
			if(W!=U){
				SS=sub[W][u];
			}if(dis[u]+w+SS<dis[v]){
				dis[v]=dis[u]+w+SS;
				q.push({{dis[v],v},W});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	_for(i,0,n,1)sub[i].resize(N);
	_for(i,1,m,1){
		int x;
		cin>>x;
		sub[0][i]=x;
	}_for(i,1,n,1){
		int k;
		cin>>k;
		int C[k+5][2];
		_for(j,1,k,1){
			cin>>C[j][1]>>C[j][2];
			sub[i][C[j][1]]=C[j][2];
		}_for(j,1,k,1){
			_for(l,1,k,1){
				if(j==l)continue;
				a[C[j][1]].push_back({{C[l][1],C[l][2]},i});
			}
		}
	}ll MM=m*m;
	if(q<=m||MM>1e8){
		while(q--){
			int u,v;
			cin>>u>>v;
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			f1(u);
			cout<<dis[v]+sub[0][v]<<"\n";
		}
	}else{
		ll Dis[m+5][m+5];
		memset(Dis,0,sizeof(Dis));
		_for(I,1,m,1){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			dis[I]=sub[0][I];
			priority_queue<
			pair<pair<ll,ll>,ll>,
			vector<pair<pair<ll,ll>,ll>>,
			greater<pair<pair<ll,ll>,ll>>> q;
			q.push({{(ll)sub[0][I],(ll)I},(ll)0});
			while(!q.empty()){
				int u=q.top().first.second,U=q.top().second;
				q.pop();
				if(vis[u])continue;
				vis[u]=1;
				int sz=a[u].size()-1;
				_for(i,0,sz,1){
					int SS=0,w=a[u][i].first.second,v=a[u][i].first.first;
					int W=a[u][i].second;
					if(W!=U){
						SS=sub[W][u];
					}if(dis[u]+w+SS<dis[v]){
						dis[v]=dis[u]+w+SS;
						q.push({{dis[v],v},W});
					}
				}
			}_for(i,1,m,1)Dis[I][i]=dis[i];
		}while(q--){
			int u,v;
			cin>>u>>v;
			cout<<Dis[u][v]+sub[0][v]<<"\n";
		}
	}
}
