#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t;
int n,k,clr[N],dis[N];
bool vis[N];
vector<int>g[N];
void dfs(int u){
	for(int v:g[u]){
		if(vis[v])continue;
		dis[v]=dis[u]+1;
	}
}
void solve(){
	cin>>n>>k;
	if(n>=4000){
		if(k>=n/2)cout<<"1\n";
		else cout<<n/k/2<<'\n';
		return;
	}
	int u,v,ans=LLONG_MAX;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=0;i<1<<n;i++){
//		cout<<i<<'\n';
	
		for(int j=1;j<=n;j++){
			clr[j]=vis[j]=(1<<(j-1))|i;
			dis[i]=0;
//			cout<<clr[i]<<'\n';
		}
		for(int j=1;j<=n;j++){
			if(clr[i])dfs(i);
			int cnt=0;
			for(int k=1;k<=n;k++){
				cnt=max(dis[k],cnt);
//				cout<<dis[k]<<' ';
			}
//			cout<<'\n';
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
