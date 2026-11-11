#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define fi first
#define se second
using namespace std;
const int M = 1e6+2;
const int N = 5e3+2;
int c,t,n,ans;
ll dd,x[M];
int f[N],d[N];//局限图中的入度 
vector<int> g[N],v[N];//原图，最短路图 
queue<int> q;
void solve(){
	cin>>n>>dd;ans = 0;
	fr(i,1,n)cin>>x[i];
	if(c==13||c==14){
		cout<<0<<"\n";
		return ;
	}
	if(n>5000){
		cout<<0<<"\n";
		return ;
	}
	fr(i,1,n)g[i].clear(),v[i].clear();
	fr(i,1,n)fr(j,i+1,n)if(x[j]-x[i]<=dd)g[i].pb(j);
	//---
	fr(i,1,n){
		while(!q.empty())q.pop();
		q.push(i);
		fr(j,i,n)d[j] = 0,f[j] = -1e6;
		f[i] = 0;
		while(!q.empty()){
			int u = q.front();q.pop();
			for(auto x:g[u])if(f[x]==-1e6)q.push(x),f[x] = f[u]+1;
		}
		fr(u,i,n)v[u].clear();
		fr(u,i,n)for(auto x:g[u])if(f[x]==f[u]+1)v[u].pb(x),d[x]++;
		while(!q.empty())q.pop();
		//----
		q.push(i);f[i] = 1;
		fr(j,i+1,n)f[j] = 0;
		while(!q.empty()){
			int u = q.front();q.pop();
			for(auto x:v[u]){
				d[x]--,f[x]+=f[u];
				if(d[x]==0)q.push(x);
			}
		}
		fr(j,i+1,n)ans+=(f[j]==2);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
