#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define fi first
#define se second
using namespace std;
int n,k,ans;
vector<int> v[20];
bool us[20],vis[20];
int f[20][20];
void dfs(int u,int fa){
	vis[u] = 1;
	for(auto x:v[u]){
		if(x==fa||us[x]==0||vis[x]==1)continue;
		dfs(x,u);
	}
}
bool ck(){
	int cnt_t = 0;
	fr(i,1,n)vis[i] = 0;
	fr(i,1,n){
		if(cnt_t>2)return 0;
		if(us[i]==0||vis[i]==1)continue;
		dfs(i,0);cnt_t++;
	}
	if(cnt_t>2)return 0;
	else return 1;
}
void dfss(int u,int sum){
	if(u==n+1){
		if(sum!=k)return ;
		if(ck()==0)return ;
		int res = 0;
		fr(i,1,n){
			int rss = 1e8;
			fr(j,1,n)if(us[j]==1)rss = min(rss,f[i][j]);
			res = max(rss,res);
		}
		ans = min(ans,res);
		return ;
	}
	us[u] = 0,dfss(u+1,sum);
	if(sum<k)us[u] = 1,dfss(u+1,sum+1); 
}
void dfp(int rt,int u,int fa,int dep){
	f[rt][u] = f[u][rt] = dep;
	for(auto x:v[u]){
		if(x==fa)continue;
		dfp(rt,x,u,dep+1);
	}
}
void solve(){
	cin>>n>>k;ans = 1e8;
	fr(i,1,n)v[i].clear();
	fr(i,2,n){
		int s1,s2;cin>>s1>>s2;
		v[s1].pb(s2);v[s2].pb(s1);
	}
	fr(i,1,n)dfp(i,i,0,0);
	dfss(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
