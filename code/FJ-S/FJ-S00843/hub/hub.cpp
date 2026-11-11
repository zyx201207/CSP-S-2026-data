#include<bits/stdc++.h>
#define ll long long
#define PLL pair<ll,ll>
using namespace std;
const int N=1000010;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
ll n,K;

namespace case1{
ll e[N<<1],ne[N<<1],h[N],tot;

ll dep[N],Max[N];
ll f[N],g[N];

ll X,Y;
vector<ll> V;
vector<PLL> v;
ll s1[N];
ll Min[N];

void dfs(ll u,ll fa,ll deep){
	dep[u]=deep;if(dep[u]>dep[X]) X=u;Max[u]=deep;
	for(int i=h[u];i!=0;i=ne[i]){
		if(e[i]==fa||s1[e[i]]) continue;
		dfs(e[i],u,deep+1);
		Max[u]=max(Max[u],Max[e[i]]);
	}
}

bool dfs2(ll u,ll fa){
	if(u==X){
		V.push_back(u);
		return 1;
	}
	for(int i=h[u];i!=0;i=ne[i]){
		if(e[i]==fa) continue;
		if(dfs2(e[i],u)){
			V.push_back(u);
			return 1;
		}
	}
	return 0;
}

void dfs3(ll u,ll fa,ll X,ll Maxn,ll rt){
	f[u]=1;Maxn++;if(rt!=u) Maxn=max(Maxn,0ll);
	
	ll pos=0,pos2=0;
	Max[0]=Maxn+dep[u];
	for(int i=h[u];i!=0;i=ne[i]){
		if(e[i]==fa||s1[e[i]]) continue;
		if(Max[e[i]]-1>X){
			if(Max[e[i]]>Max[pos]) pos2=pos,pos=e[i];
			else if(Max[e[i]]>Max[pos2]) pos2=e[i];
		}
	}
			
	for(int i=h[u];i!=0;i=ne[i]){
		if(e[i]==fa||s1[e[i]]) continue;
		Max[0]=Maxn+dep[u];
		if(e[i]!=pos) dfs3(e[i],u,X,Max[pos]-dep[u],rt);
		else dfs3(e[i],u,X,Max[pos2]-dep[u],rt);
		if(Max[e[i]]-dep[e[i]]>=X) f[u]+=f[e[i]];
	}
	if(Maxn<=X){
		g[rt]=min(g[rt],f[u]);
	}
}

bool check(ll X){
	ll ans=0;
	for(int i=0;i<V.size();i++){
		g[V[i]]=INF,dfs3(V[i],0,X,-INF,V[i]);
//		if(X==1) cout<<endl;
	}
	v.clear();
	for(int i=0;i<V.size();i++){
		ans+=f[V[i]]-1;
		if(Max[V[i]]-1>=X) v.emplace_back(i,i);
		else v.emplace_back(max(0ll,i-(X-Max[V[i]]+1)),min((ll)(V.size()-1),i+(X-Max[V[i]]+1)));
	}
	
	ll L=V.size()+1,R=0;
	for(int i=0;i<v.size();i++) L=min(L,v[i].second),R=max(R,v[i].first);
	
	if(L>=R) return ans+1<=K;
	
	for(int i=0;i<V.size();i++) Min[i]=V.size()+1;
	for(int i=0;i<v.size();i++){
		if(L>=v[i].first||R<=v[i].second) continue;
		Min[v[i].first]=min(Min[v[i].first],v[i].second);
	}
	ll res=INF,Ls=R;
	for(int i=R-1;i>=L;i--){
		res=min(res,(i-L+1)+(R-Ls+1));
		Ls=min(Ls,Min[i]);
	}
	if(ans+res<=K) return 1;
	
	for(int i=L;i<=R;i++){
		if(R-L+1+(ans-(f[V[i]]-1)+g[V[i]])<=K) return 1;
	}
	return 0;
}

void add(ll x,ll y){
	e[++tot]=y,ne[tot]=h[x],h[x]=tot;
}

void solve(){
	for(int i=1;i<=n;i++) s1[i]=0,h[i]=0;tot=0;
	for(int i=1;i<n;i++){
		ll x=read(),y=read();
		add(x,y),add(y,x);
	}
	X=0;
	dfs(1,0,1);
	Y=X;X=0;
	dfs(Y,0,1);
	
	V.clear();
	dfs2(Y,0);
	
	for(int i=0;i<V.size();i++) s1[V[i]]=1;
	for(int i=0;i<V.size();i++) X=0,dfs(V[i],0,1);
	
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	write(l),putchar('\n');
}
}

namespace case2{
const int M=110;
struct node{
	ll x,y;
}a[M];

ll f[M][M];

ll s1[M];
ll ans;

void solve(){
	ans=n+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=INF;
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<n;i++){
		a[i].x=read(),a[i].y=read();
		f[a[i].x][a[i].y]=f[a[i].y][a[i].x]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	for(int i=0;i<(1<<n);i++){
		ll Cnt2=0;
		for(int j=0;j<=n;j++) s1[j]=0;
		for(int j=0;j<n;j++){
			if(i>>j&1) s1[j+1]=1,Cnt2++;
		}
		if(Cnt2!=K) continue;
		
		ll Cnt=0;
		for(int j=1;j<n;j++){
			if(s1[a[j].x]&&s1[a[j].y]) Cnt++;
		}
		if(Cnt<K-2) continue;
		
		ll res=0;
		for(int j=1;j<=n;j++){
			ll tmp=n+1;
			for(int k=1;k<=n;k++){
				if(s1[k]) tmp=min(tmp,f[k][j]);
			}
			res=max(res,tmp);
		}
		ans=min(ans,res);
	}
	write(ans),putchar('\n');
}
}

void solve(){
	n=read(),K=read();
	if(n<=16) case2::solve();
	else case1::solve();
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	read();ll T=read();
	while(T--) solve();
	return 0;
}
/*
0 1
7 3
1 2
2 3
3 4
1 5
2 6
4 7
*/
