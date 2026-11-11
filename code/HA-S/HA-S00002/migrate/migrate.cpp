#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,M=N*N,inf=0x3f3f3f3f;
int tot,head[N],nex[M],to[M],deg[N];
void addEdge(int u,int v){
	to[++tot]=v,nex[tot]=head[u],head[u]=tot;
}
struct A{
	int dis,cnt;
	A operator+(const A& b){
		if(dis!=b.dis)return dis<b.dis?*this:b;
		return A{dis,cnt+b.cnt};
	}
	A& operator+=(const A& b){
		return (*this=*this+b);
	}
}s[N];
int c,T,n,q[N],l,r;ll d,x[N];
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
	if(n<=3){
		cout<<0<<'\n';
		return;
	}
	ll k = x[2]-x[1];
	d=d/k;
	if(d<=1){
		cout<<0<<'\n';
		return;
	}
	ll ans = max(0ll,n-3-2*(d-2));
	cout<<ans<<'\n';
}
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("migrate");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	while(T--){
		if(c==11||c==12){
			solve1();
			continue;
		}
		cin>>n>>d;
		for(int i=1;i<=n;++i)head[i]=0;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			for(int j=i-1;j>=1&&x[i]-x[j]<=d;--j){
				addEdge(j,i);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				for(int e=head[j],v;e;e=nex[e]){
					v=to[e];
					deg[v]++;
				}
			}
			s[i]={0,1};
			for(int j=i+1;j<=n;++j)s[j]={inf,0};
			l=r=0;
			q[r++]=i;
			while(l<r){
				int u=q[l++];
				for(int e=head[u],v;e;e=nex[e]){
					v=to[e];
					A tmp=s[u];tmp.dis++;
					s[v]+=tmp;
					if(!--deg[v])q[r++]=v;
				}
			}
			for(int j=i+1;j<=n;++j)if(s[j].cnt==2)++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
