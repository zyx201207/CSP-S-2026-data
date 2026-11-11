#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int BUF=1<<20;
char buf[BUF],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2)p2=(p1=buf)+fread(buf,1,BUF,stdin);
	return p1==p2?EOF:*p1++;
}
template<class T=ll>T read(T&&x=T()){
	x=0;int fg=1;
	char c=gc();
	while(!isdigit(c))
		fg-=(c=='-')<<1,c=gc();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=gc();
	return x*=fg;
}
const int N=2e6+6;
ll x[N];
ll nxt[N],fa[N],vis[N],val[N],key[N],h[N],g[N],falg[N];
void solve(){
	int n=read();ll d=read();
	for(int i=1;i<=n;i++){
		read(x[i]),key[i]=1,falg[i]=1;
	}
	auto sol=[&](ll*f){
		for(int i=1,j=0;i<=n;i++){
			while(j<n&&x[j+1]-x[i]<=d)
				j++;
			nxt[i]=j;
		}
		for(int i=1;i<n;i++){
			int p=nxt[i],c=i;
			if(p==i+1){
				key[p]+=key[i];
				continue;
			}
			f[p]+=key[i];
			while(1){
				if(vis[p])break;
				vis[p]=1;
				int px=nxt[p];
				// if(col[px]!=c)col[px]=c,dis[px]=dis[p]+1;
				// if(px-1!=p&&col[px-1]!=c)col[px-1]=c,dis[px-1]=dis[p]+1;
				// if(col[px]==c&&dis[px]<=dis[p]+1)break;
				// if(col[px-1]==c&&dis[px-1]<=dis[p]+1)break;
				if(nxt[p]==nxt[p-1]||(nxt[p-1]==nxt[p]-1&&(nxt[p-1]!=p)))break;
				if(nxt[p-1]==p)falg[p]=0;
				fa[p]=nxt[p];
				p=fa[p];
			}
		}
		for(int i=1;i<=n;i++){
			f[i]+=val[i];
			val[fa[i]]+=f[i];
			f[i]-=(1-falg[i])*val[i];
		}
	};
	sol(h);
	// for(int i=1;i<=n;i++)
	// 	cout<<h[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++)
	// 	cout<<fa[i]<<" \n"[i==n];
	// for(int i=1;i<=n;i++)
	// 	cout<<nxt[i]<<" \n"[i==n];
	reverse(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		x[i]=n-x[i]+1;
		vis[i]=val[i]=fa[i]=nxt[i]=0,key[i]=1,falg[i]=1;
	}
	sol(g);
	ll ans=0;
	for(int i=1;i<n;i++)
		ans+=h[i+1]*g[n-i+1];
	// for(int i=n;i>=1;i--)
	// 	cout<<g[i]<<" \n"[i==1];
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		x[i]=vis[i]=val[i]=fa[i]=nxt[i]=key[i]=h[i]=g[i]=0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		solve();
	}
}
