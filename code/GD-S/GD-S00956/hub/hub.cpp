#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep1(i,s,t) for(int i=s;i>t;i--)
#define set(ai,k) memset(ai,k,sizeof(ai))
#define srt(ai,n) sort(ai+1,ai+1+n)
#define csrt(ai,n,cmp) sort(ai+1,ai+1+n,cmp)
#define pb push_back
using namespace std;
const int N=1e5+5;
int c,t,n,k,a,b,ai[N],ans=1e9,f[N];
queue<int>qi;
bool vis[N];
vector<int>vi[N];
void dfs(int x){
	vis[x]=1;
	for(auto v:vi[x]){
		if(!vis[v]&&ai[v])dfs(v);
	}
}
void slv(int x){
	if(x>n){
		int sm=0;
		rep(i,1,n)sm+=ai[i];
		if(sm!=k)return;
		sm=0;
		rep(i,1,n)vis[i]=0;
		rep(i,1,n){
			if(ai[i]&&!vis[i])dfs(i),sm++;
		}
		if(sm>2)return;
		rep(i,1,n){
			if(ai[i])f[i]=0,qi.push(i);
			else f[i]=1e9;
		}
		while(!qi.empty()){
			int x=qi.front();
	//		cout<<"HI "<<x<<endl;
			qi.pop();
			for(auto v:vi[x]){
		//		cout<<x<<" "<<v<<endl;
				if(f[v]<1e9)continue;
				f[v]=f[x]+1;
				qi.push(v);
			}
		}
		sm=0;
		rep(i,1,n)sm=max(sm,f[i]);
		ans=min(ans,sm);
//		cout<<"YO"<<endl;
//		rep(i,1,n){
//			cout<<ai[i]<<" ";
//		}cout<<endl;
//		rep(i,1,n){
//			cout<<f[i]<<" ";
//		}cout<<endl;
		return;
	}
	ai[x]=1;
	slv(x+1);
	ai[x]=0;
	slv(x+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		cin>>n>>k;
		rep1(i,1,n)cin>>a>>b,vi[a].pb(b),vi[b].pb(a);
		slv(1);
		rep(i,1,n)vi[i].clear();
		cout<<ans<<endl;
	}
}
