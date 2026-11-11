#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int w[501010];
int ebt[505005];
struct node{
	int v,t,qt,sn;
};
struct point{
	int u,t,bf;
};
int st,en;
int ans;
int vis[505050];
vector<node>e[501010];
void dfs(int u,int t,int bf,int sn){
//	cout<<u<<' '<<t<<' '<<bf<<' '<<sn<<endl;
	if(u==en){
		ans=min(ans,t+w[en]);
		return;
	}
	for(auto nx:e[u]){
		if(vis[nx.v]>=1){
			continue;
		}
		vis[nx.v]++;
		if(sn==nx.sn){
			dfs(nx.v,t,u,nx.sn);
		}else{
			dfs(nx.v,t+nx.t+nx.qt,u,nx.sn);
		}
		vis[nx.v]--;
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ebt,127,sizeof ebt);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int tmpc=0;
	int tmpa=0,tmpb=0;
	int rta=0,rtb=0;
	for(int i=1;i<=n;i++){
		cin>>tmpc;
		for(int j=1;j<=tmpc;j++){
			rta=tmpa;
			rtb=tmpb;
			cin>>tmpa>>tmpb;
			if(j>=2){
				e[rta].push_back({tmpa,tmpb,rtb,i});
				e[tmpa].push_back({rta,rtb,tmpb,i});
				ebt[rta]=min(ebt[rta],rtb);
				ebt[tmpa]=min(ebt[tmpa],tmpb);
			}
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,0,sizeof vis);
		ans=1e9;
		cin>>st>>en;
		vis[st]=1;
		dfs(st,w[st],-1,-1);
		cout<<ans<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
