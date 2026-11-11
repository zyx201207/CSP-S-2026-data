#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define per(i,r,l) for(int i=(r),i##end=(l);i>=i##end;--i)
using namespace std;
const int maxn=1e6+10,maxm=1e6+10,mod=998244353;
inline int ksm(int x,int k,int mod=mod){
	int ans=1;
	for(;k;k>>=1,x=x*x%mod) if(k&1) ans=ans*x%mod;
	return ans;
}

int testid,T;
int n,k,rt[maxn],isrt[maxn],rt1,rt2,rtot,fa[maxn],fd[maxn],dep[maxn],mxdep[maxn];
int mxdp[maxn],ans,flg[maxn];
vector<int> e[maxn];

void dfs1(int x){
	for(int i:e[x]) if(i!=fa[x]&&!isrt[i]) fa[i]=x,dep[i]=dep[x]+1,fd[i]=fd[x],dfs1(i);
}
void dfs2(int x){
	mxdep[x]=dep[x];
	for(int i:e[x]) if(i!=fa[x]&&!isrt[i]) fa[i]=x,dep[i]=min(dep[i],dep[x]+1),
		fd[i]=fd[x],dfs1(i),mxdep[x]=max(mxdep[x],dep[i]);
}

signed submain(){
	cin>>n>>k,rtot=0,ans=0;
	rep(i,1,n) e[i].clear(),mxdp[i]=isrt[i]=flg[i]=0;
	rep(i,1,n-1){
		int u,v;
		cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	}
	dep[1]=0,fa[1]=0,dfs1(1);
	rep(i,1,n) if(dep[i]>dep[rt1]) rt1=i;
	dep[rt1]=0,fa[rt1]=0,dfs1(rt1);
	rep(i,1,n) if(dep[i]>dep[rt2]) rt2=i;
	for(int x=rt2;x;x=fa[x]) isrt[x]=1,rt[++rtot]=x,dep[x]=0,fd[x]=rtot;
	rep(i,1,rtot) dfs1(rt[i]);
	rep(i,1,n) mxdp[fd[i]]=max(mxdp[fd[i]],dep[i]);
	
	int mid=1+rtot>>1,mdx=1,val=0;
	rep(i,1,mid) if(i-mxdp[i]>val) val=i-mxdp[i],mdx=i;
	per(i,rtot,mid) if(rtot-i+1-mxdp[i]>val) val=rtot-mid+1-mxdp[i],mdx=i;
	
	int ls=1+mdx+mxdp[mdx]>>1,rs=rtot+mdx-mxdp[mdx]>>1;
	priority_queue<pair<int,int>> t;
	
	rep(i,1,n) dep[i]=1e9,isrt[i]=0,fa[i]=0;
	dep[rt[ls]]=0,dep[rt[rs]]=0,dfs2(rt[ls]),dfs2(rt[rs]);
//	rep(i,1,n) cout<<mxdep[i]<<",\n"[i==iend];
	t.push(make_pair(0,rt[ls])),t.push(make_pair(0,rt[rs]));
	
	rep(i,1,k){
		int x=t.top().second;
//		cout<<t.top().first<<',';
		t.pop(),flg[x]=1;
//		cerr<<x<<')';
		for(int j:e[x]) if(j!=fa[x]&&!isrt[j]) fa[j]=x,t.push((pair<int,int>){-mxdep[j],j});
	}
	
//	cout<<rt[ls]<<','<<rt[rs]<<']';
	
	rep(i,1,n) isrt[i]=flg[i],fa[i]=0,dep[i]=1e9;
	rep(i,1,n) if(flg[i]) dep[i]=0,dfs2(i);
	rep(i,1,n) ans=max(ans,dep[i]);
	cout<<ans<<'\n';
	return 0;
}

signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>testid>>T;
	rep(o,1,T){
		submain();
	}
	return 0;
}/*
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
