#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int MAX=1e9;
int op,T;
int n,m;
vector<int>s[N];
bool vis[N];
bool vss[N];
int dp[N];
void dfs(int x,int fa,int mb){
	if(s[x].size()==1){
		dp[x]=1;
	}
	int len=MAX;
	for(int i=0;i<s[x].size();i++){
		int v=s[x][i];
		if(v==fa)continue;
		dfs(v,x,mb);
		if(vss[v]){
			len=min(len,dp[v]+1);
		}
		vss[x]=(vss[x]|vss[v]);
	}
	int ma=0;
	for(int i=0;i<s[x].size();i++){
		int v=s[x][i];
		if(v==fa)continue;
		if(dp[v]+len<=mb&&dp[v]+1!=len)continue;
		dp[x]=max(dp[x],dp[v]+1);
	}
	if(dp[x]>mb){
		vss[x]=vis[x]=1;
		dp[x]=0;
	}
}
int deep[N];
int cnt=0;
int ma=0;
bool mark=0;
void dfs1(int x,int fa){
	deep[x]=deep[fa]+1;
	if(vis[x]){
		vss[x]=1;
	}
	int ct=0;
	for(int i=0;i<s[x].size();i++){
		int v=s[x][i];
		if(v==fa)continue;
		dfs1(v,x);
		if(vss[v]){
			dp[x]=max(dp[x],dp[v]+1);
			ct++;
		}
		vss[x]|=vss[v];
	}
	ma=max(ma,dp[x]-1);
	if(vis[x]||ct>=2){
		dp[x]=0;
	}
	if(vss[x])cnt++;
}
bool check(int x){
	for(int i=1;i<=n;i++){
		dp[i]=0;
		vis[i]=0;
		vss[i]=0;
		deep[i]=0;
	}
	dfs(1,1,x);
	for(int i=1;i<=n;i++){
		vss[i]=0;
		dp[i]=0;
	}
	ma=0;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			dfs1(i,i);
			break;
		}
	}
	int sum=cnt-ma;
	return sum<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>op>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)s[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			s[x].push_back(y);
			s[y].push_back(x);
		}
		int l=-1,r=n+1,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid;
		}
		cout<<r<<'\n';
	}
	return 0;
}/*
0 1
12 2
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
4 11
11 12

0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
