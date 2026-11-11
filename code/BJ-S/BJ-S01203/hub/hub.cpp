#include<bits/stdc++.h>
using namespace std;
#define CO const
#define CC constexpr
#define CA CO auto
#define RE return
#define VE vector
#define PB push_back
#define FI first
#define SE second
#define TET template<class T>
using ll=long long;
using Ci=CO int;using Cl=CO ll;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define FER(i,r,l) for(int i=(r);i>=(l);--i)
#define FVR(y) for(Ci y:v[x])if(y!=fx)
TET using pq=priority_queue<T,VE<T>,greater<>>;
TET CC void Max(T&x,T y){x=max(x,y);}
TET CC void Min(T&x,T y){x=min(x,y);}
CC int N=1e6+5;CC ll Mx=1e18;
int zq,T;
int n,m,s;
VE<int>v[N];
int de[N];
void dfd(Ci x,Ci fx){
	de[x]=de[fx]+1;
	FVR(y)dfd(y,x);
}
bool dfg(Ci x,Ci fx,Ci r,Ci k){
	bool fl=x==r;
	FVR(y)fl|=dfg(y,x,r,k);
	if(fl&&de[x]==k)s=x;
	RE fl;
}
void gets(){
	dfd(1,0);
	Ci l=max_element(de+1,de+1+n)-de;
	dfd(l,0);
	Ci r=max_element(de+1,de+1+n)-de,k=de[r];
	dfg(l,0,r,(k+1)/2);
}
void dfk(Ci x,Ci fx){
	de[x]=1;
	FVR(y)dfk(y,x),Max(de[x],de[y]+1);
}
int mi,su,an;
int f[N],g[N];
void dfs(Ci x,Ci fx){
	f[x]=1,g[x]=mi+1,++su;
	int k=0,kk=1;
	FVR(y){if(de[y]>mi){
		dfs(y,x);
		Max(f[x],f[y]+1);
		kk+=f[y];
	}else Min(g[x],mi-de[y]);}
	f[x]=min(f[x],g[x]-1);
	if(k>1)f[x]=0;
	if(x==s&&k==2)Max(an,min(kk,g[x]*2-1));
	Max(an,f[x]);
}
bool che(){
	su=an=0;
	dfs(s,0);
	RE (su-an<=m);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>zq>>T;
	while(T--){
		cin>>n>>m;
		FOR(i,1,n-1){
			int x,y;cin>>x>>y;
			v[x].PB(y),v[y].PB(x);
		}
		gets(),dfk(s,0);
		int l=-1,r=de[s]-1;
		while(l+1<r){
			mi=(l+r)/2;
			(che()?r:l)=mi;
		}
		cout<<r<<'\n';
		FOR(i,1,n)v[i].clear();
	}
	RE 0;
}