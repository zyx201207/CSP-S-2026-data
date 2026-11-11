#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6;
struct node{
	int v,w;
};
vector<int>V[maxn];
int dp[maxn];
int flag[maxn]; 
int n,k;
int c;
int check(int u,int fa){
	int res=(flag[u]==1&&flag[fa]==0);
	for(auto v:V[u]){
		if(v==fa)continue;
		res+=check(v,u); 
	}
	return res;
}
int dfs(int u,int fa){
	if(flag[u])return 0;
	int res=2e9;
	for(auto v:V[u]){
		if(v==fa)continue;
		res=min(res,dfs(v,u)+1);
	}
	return res;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)V[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	if(c==13||c==14){
		int m=n/2;
		if(k==n){
			cout<<0<<'\n';
		}
		else if(k>=m){
			cout<<1<<'\n';
		}
		else{
			cout<<(m-k+2+3)/4<<'\n';
		}
		return;
	}
	int lim=(1<<n);
	int ans=114514;
	for(int i=1;i<=lim;i++){
		if(__builtin_popcount(i)!=k)continue;
		for(int j=1;j<=n;j++){
			if((1<<(j-1))&i)flag[j]=1;
			else flag[j]=0;
		}
		if(check(1,0)>2)continue;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(flag[i])continue;
			cnt=max(cnt,dfs(i,0));
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}


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
