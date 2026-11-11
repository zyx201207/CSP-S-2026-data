#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=(int)b;i>=(int)a;i--)
#define ll long long
#define ull unsigned long long
const int N=1e6+10;
const ll mod=1e9+7;
const ll inf=1e18+10;
using Vl=vector<int>;
using PI=array<int,2>;
int cid,T,n,mx;ll d,a[N],dep[N],ct[N];
vector<PI> g[N];
#define ls (id<<1)
#define rs (id<<1|1)
inline void init(int id,int l,int r){
	mx=max(mx,id);
	if(l==r) return g[id+n].push_back({l,0}),void();
	int mid=l+r>>1;init(ls,l,mid),init(rs,mid+1,r);
	g[id+n].push_back({ls+n,0}),g[id+n].push_back({rs+n,0});return ;
}
inline void A(int id,int l,int r,int L,int R,int u){
	if(L<=l&&r<=R) return g[u].push_back({id+n,1});
	int mid=l+r>>1;
	if(L<=mid) A(ls,l,mid,L,R,u);
	if(mid<R) A(rs,mid+1,r,L,R,u);
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>cid>>T;
	while(T--){
		FOR(i,1,n) dep[i]=ct[i]=0;
		FOR(i,1,mx) g[i].clear();
		cin>>n>>d;mx=0;
		FOR(i,1,n) cin>>a[i];
		//init(1,1,n);
		mx+=n;
		int r=n;ll ans=0;
		ROF(i,1,n-1){
			while(a[i]+d<a[r]) r--;
//			if(i<r) A(1,1,n,i+1,r,i);
			FOR(j,i+1,r) g[i].push_back({j,1});
			FOR(j,i+1,mx) dep[j]=mod,ct[j]=0;
			priority_queue<PI> q;q.push({dep[i]=0,i});ct[i]=1;
			while(!q.empty()){
				PI tp=q.top();q.pop();
				int dd=-tp[0],u=tp[1];
				if(dep[u]!=dd) continue;
				if(u<=n&&ct[u]==2) ans++;
				for(auto vv:g[u]){
					int v=vv[0],w=vv[1];
					if(dep[v]>dep[u]+w) ct[v]=ct[u],q.push({-(dep[v]=dep[u]+w),v});
					else if(dep[v]==dep[u]+w) ct[v]+=ct[u];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
