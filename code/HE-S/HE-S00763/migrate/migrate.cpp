#include<bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;
const int inf = 1e18;
int T,n,d,c,cnt,ans;
int X[N],vis[N];
vector<int> g[N];
inline int ABS(int x){
	return (x>0?x:-x);
}
void init(){
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ABS(X[i]-X[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
}
void dfs(int u,int v,int step){
	vis[u]=1;
	if(u==v){
		if(step<ans) ans=step;
		vis[u]=0;
		return;
	} 
	for(auto x : g[u]){
		if(!vis[x]){
			dfs(x,v,step+1);
		}		
	}
	vis[u]=0;
}
void dfs1(int u,int v,int step){
	vis[u]=1;
	if(u==v){
//		cout<<"arrive,step="<<step<<'\n';
		if(step==ans) cnt++;
		vis[u]=0;
		return;
	} 
	for(auto x : g[u]){
		if(!vis[x]){
			dfs1(x,v,step+1);
		}		
	}
	vis[u]=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>X[i];
		init();
		int ANS=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0,ans=inf;
				dfs(i,j,0);
				dfs1(i,j,0);
				if(cnt==2){
					ANS++;
//					cout<<"i="<<i<<"j="<<j<<"ans="<<ans<<"cnt="<<cnt<<'\n';
				} 
			}
		}
		cout<<ANS<<'\n';
	}
	return 0;
}
