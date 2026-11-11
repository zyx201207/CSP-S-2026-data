#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int cid,T,n,k;
vector<int> f[N][N];
vector<int> G[N];
int l1[N],l2[N],fir[N];

int dfs(int p,int fa){
	int len=0;
	for(int v:G[p]) if(v^fa) len=max(len,dfs(v,p)+1);
	return len;
}
inline int qlen(int p,int fa){
	if(fir[p]==fa) return l2[p];
	return l1[p];
}
void dp(int p,int fa){
	if(!f[p][fa].empty()) return;
	f[p][fa].resize(n,1);
	for(int v:G[p]) if(v!=fa){
		dp(v,p);
		int len=qlen(v,p)+1;
		for(int i=0;i<len;++i) f[p][fa][i]+=f[v][p][i];
	}
//	cerr<<"F"<<p<<' '<<fa<<' '<<f[p][fa][1]<<'\n';
}
vector<int> len[N][N];
void dp2(int p,int root,int i,int fa,int w){
	len[root][i][p]=w;
	//if(root==1) cerr<<"len"<<i<<' '<<p<<' '<<w<<'\n';
	int fir=0,fx=0,se=0;
	for(int v:G[p]) if(v^fa){
		if(p==root&&i==v) continue;
		int now=qlen(v,p)+1;
		if(now>fir) se=fir,fir=now,fx=v;
		else se=max(se,now);
	}
	for(int v:G[p]) if(v^fa) dp2(v,root,i,p,max(w,fx==v?se:fir)+1);
}
int ans,stk[N];
void calc(int p,int root,int fa,int dep){
	stk[dep]=p;
	if(p!=root){
		int lim=1;
		int mid=(dep+1)/2;
		lim=max(lim,len[stk[mid]][stk[mid-1]][p]);
		lim=max(lim,len[stk[mid-1]][stk[mid]][root]);
		if(lim>=ans) return;
		dp(p,fa),dp(root,stk[1]);
		while(ans-1>=lim&&f[p][fa][ans-1]+f[root][stk[1]][ans-1]<=k) --ans;
	}
	for(int v:G[p]) if(v^fa) calc(v,root,p,dep+1);
}
void calc1(int p,int fa,int dep){
	stk[dep]=p;
	int lim=1;
	if(p!=1) lim=max(lim,len[1][stk[1]][p]);
	dp(p,fa);
	while(ans-1>=lim&&f[p][fa][ans-1]<=k) --ans;
	for(int v:G[p]) if(v^fa) calc1(v,p,dep+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cid>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(k>=n){
			cout<<0<<'\n';
			for(int i=1;i<=n;++i) G[i].clear();
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int v:G[i]){
				int now=dfs(v,i)+1;
				if(now>l1[i]) l2[i]=l1[i],l1[i]=now,fir[i]=v;
				else l2[i]=max(l2[i],now);
			}
		}
		for(int i=1;i<=n;++i)
		for(int v:G[i]){
			len[i][v].resize(n+1);
			dp2(i,i,v,0,0);
		}
		ans=n-1;
		for(int i=1;i<=n;++i) calc(i,i,0,0);
		calc1(1,0,0);
		cout<<ans<<'\n';
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n;++j){
				if(!f[i][j].empty()) f[i][j].clear();
				if(!len[i][j].empty()) len[i][j].clear();
			}
			G[i].clear();
			l1[i]=l2[i]=fir[i]=0;
		}
	}
	return 0;
}

