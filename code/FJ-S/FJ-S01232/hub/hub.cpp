#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll c,t,n,k,u,v,ans,vis[N],a[N];
vector<ll> g[N];
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs2(ll u,ll f){
	vis[u]=1;
	for(auto v:g[u]){
		if(v==f) continue;
		dfs2(v,u);
	}
}
ll dfs3(ll u,ll f,ll dis){
	if(a[u]) return dis;
	ll res=1e9;
	for(auto v:g[u]){
		res=min(res,dfs3(v,u,dis+1));
	}
	return res;
}
ll check(){
	ll res=0;
	for(int i=1;i<=n;i++){
		if(!a[i]) res=max(res,dfs3(i,0,0));
	}
	return res;
}
void dfs(ll u,ll cnt){
	if(cnt>k) return ;
	if(u>n){
		if(cnt!=k) return ;
		memset(vis,0,sizeof vis);
		ll ccnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i] && a[i]){
				dfs2(i,0);
				ccnt++;
			}
		}
		if(ccnt>2) return ;
		ans=min(ans,check());
		return ;
	}
	dfs(u+1,cnt);
	a[u]=1;
	dfs(u+1,cnt+1);
	a[u]=0;
}
int main(){
	freopen("hub.in.in","r",stdin);
	freopen("hub.in.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=1e9;
		n=read(),k=read();
		for(int i=1;i<n;i++){
			u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
