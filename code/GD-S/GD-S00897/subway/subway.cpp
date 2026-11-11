#include <bits/stdc++.h>
using namespace std;
constexpr int M=5e5+10;
int w[M];
#define piv pair<int,vector<int>>
#define fi first
#define se second
map<int,piv>mp[M];//第m条线 第i个站 fi:厅->台 时间  se:去哪里 
vector<int>turn[M];//第m个站有哪些线
long long ans;
long long dist[M];
void dfs(int end,int u,int fa,int now,long long t){//now:now line
	dist[u]=min(dist[u],t);
//	cout<<fa<<"->"<<u<<" :"<<t<<'\n';if(u==5) cout<<"check"<<dist[5]<<endl;
	if(u==end){
		t+=mp[now][u].fi;
		dist[u]=min(dist[u],t);	
		ans=min(ans,t);
		return;
	}
//	if(turn[u].size()==1){
//		for(auto v:mp[now][u].se){
//			if(v==fa) continue;
//			dfs(v,u,now,t);
//		}
//	}
//	else{
	for(auto i:turn[u]){
//		if(u==4) cout<<"check  "<<i<<endl;
		for(auto v:mp[i][u].se){
			if(v==fa) continue;
//			cout<<u<<" "<<v<<endl;
			if(dist[u]>dist[v]) continue; 
			long long temp=dist[v];
//			if(v==5) cout<<"check  "<<dist[5]<<endl;
			if(i==now) dfs(end,v,u,now,t);
			else{
			dfs(end,v,u,i,t+mp[now][u].fi+mp[i][u].fi);}
			dist[v]=temp;
//			if(v==5) cout<<"check2"<<" "<<dist[5];
		}
	}
}
void solve(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		vector<int>ve; 
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			mp[i][a].fi=t;
			ve.push_back(a);
			turn[a].push_back(i);
		}
		for(int j=1;j<k;++j){
			int u=ve[j],v=ve[j-1];
//			if(i==2){
//				cout<<"check:";
//				for(auto check:ve) cout<<check<<" ";
//				cout<<endl;
//			}
			mp[i][u].se.push_back(v);
			mp[i][v].se.push_back(u);
		}
	}
//	for(auto i:mp[2][2].se) cout<<"check"<<i<<" ";
//	for(auto i:turn[2]) cout<<i<<" and ";
//	cout<<endl;
	while(q--){
		for(int i=1;i<=m;++i) dist[i]=1e18;
		ans=INT_MAX;
		int st,ed;
		cin>>st>>ed;
		for(auto i:turn[st]) dfs(ed,st,-1,i,mp[i][st].fi);
//		for(int i=1;i<=m;++i){
//			cout<<dist[i]<<" ";
//		}
//		cout<<endl;
//		cout<<ans<<endl;
		cout<<ans+w[st]+w[ed]<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
35
16
*/
