#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000;
struct node{
	ll x,dis;
	bool operator<(const node& a) const {return a.dis<dis;}
};
int c,t,n,k,p[N],o[N],l,vis[N];
ll dis[N];
vector<int> v[N];
priority_queue<node> q;

void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		int u=v[x][i];
		if((!vis[u])&&o[u]) dfs(u);
	}
}

bool ok(int x){
	memset(vis,0,sizeof(vis));
	memset(o,0,sizeof(o));
	l=0;
	for(int i=0;i<n;i++){
		if(x&(1<<i)) p[++l]=i+1,o[i+1]=1;
	}
	if(l!=k) return 0;
	int sum=0;
	for(int i=1;i<=l;i++){
		if(!vis[p[i]]) dfs(p[i]),sum++;
	}
	return sum<=2;
}

void dijkstra(){
	while(!q.empty()){
		node now=q.top();q.pop();
		for(int i=0;i<v[now.x].size();i++){
			int u=v[now.x][i];
			if(dis[u]>dis[now.x]+1){
				dis[u]=dis[now.x]+1;
				q.push({u,dis[u]});
			}
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ll cnt=2e18;
		for(int i=0;i<(1<<n);i++){
			if(ok(i)){
				memset(dis,127,sizeof(dis));
				for(int j=1;j<=n;j++){
					if(i&(1<<(j-1))) dis[j]=0,q.push({j,0});
				}
				dijkstra();
				ll ans=0;
				for(int j=1;j<=n;j++) ans=max(dis[j],ans);
				cnt=min(cnt,ans);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
