#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define N 1000005
using namespace std;
int read(){
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int INF=1e9;
int C,T,n,k,ans;
vector<int>e[N];
int s[N]; bool bz[N];
int fa[N];
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);	}
bool check(){
	for(int i=1;i<=k;i++) fa[s[i]]=s[i];
	int u;
	for(int i=1;i<=k;i++){
		u=s[i];
		for(int v:e[u])
			if(bz[v]) fa[find(u)]=find(v);
	}
	int cnt=0;
	for(int i=1;i<=k;i++) if(fa[s[i]]==s[i]) cnt++;
	return cnt<=2;
}
queue<int>q; int dis[N];
void calc(){
//	for(int i=1;i<=k;i++) cout<<s[i]<<" "; cout<<endl;
	for(int i=1;i<=n;i++) dis[i]=INF;
	for(int i=1;i<=k;i++) dis[s[i]]=0,q.push(s[i]);
	int u;
	while(!q.empty()){
		u=q.front(); q.pop();
		for(int v:e[u]){
			if(dis[v]!=INF) continue;
			dis[v]=dis[u]+1,q.push(v);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,dis[i]);
	ans=min(ans,res);
}
void dfs(int pos){
	if(pos>k){
		if(k==2||check()) calc(); return ;
	}
	else {
		for(int i=1;i<=n;i++){
			if(!bz[i]){
				s[pos]=i,bz[i]=1;
				dfs(pos+1); bz[i]=0;
			}
		}
	}
}
void solve(){
	ans=INF;
	n=read(),k=read();
	for(int i=1;i<=n;i++) e[i].clear();
	int u,v;
	for(int i=1;i<n;i++){
		u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1);
	write(ans); putchar('\n');
}
void solve2(){
	n=read(),k=read();
	int u,v;
	for(int i=1;i<n;i++)
		u=read(),v=read();
//	cout<<n<<" "<<k<<endl;
	if(k*2>=n){
		if(k==n) puts("0");
		else puts("1");
		return ;
	}
	write(((n/2-k)+3)/4+1); putchar('\n');
//	write(((n+1-k*2)/8)+1); putchar('\n');
//	n=n+1>>1;
//	write(((n-k+2)/3+1)/2); putchar('\n');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read(),T=read();
//	solve2(); 
	if(C==13||C==14) solve2();
	else while(T--) solve();
    return 0;
}
