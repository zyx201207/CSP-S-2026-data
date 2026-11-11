/*
-fsanitize=address,undefined

ios::sync_with_studio(0);
cin.tie(0);

cout<<fixed<<precision();

想到15:10 

期望100pts 
可能得考虑加一个快读 
*/
#include <bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define pii pair<ll,ll>
#define mkp make_pair
#define fir first
#define sec second
using namespace std;

namespace mycode{
	const int MAXN=505;
	const int MAXM=5e5+5;
	const ll inf=1e18;
	int n,m,d,q;
	ll w[MAXM];
	vector<pii> st[MAXM];//对应的线路,<编号，权值> 
	ll G[MAXN][MAXN];//节点图 
	
	void add(int v,int idx,ll val){//指向v 
		for(pii p:st[v]) G[idx][p.fir]=G[p.fir][idx]=min(G[idx][p.fir],val+p.sec);
		st[v].push_back(mkp(idx,val));
	}//建新边 
	
	void floyd(){
		FOR(k,1,n)FOR(i,1,n)FOR(j,1,n) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	}
	
	ll query(int x,int y){//保证不同 
		ll res=inf;
		for(pii px:st[x])for(pii py:st[y])res=min(res,px.sec+py.sec+G[px.fir][py.fir]);
		return res+w[x]+w[y];
	}
	
	ll read(){
		ll t=0;
		char ch=getchar();
		while(!(ch>='0'&&ch<='9')) ch=getchar();
		while(ch>='0'&&ch<='9') t=t*10+(ch-'0'),ch=getchar();
		return t;
	} 
	
	int main(){
		int c;scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
		FOR(i,1,m) w[i]=read();
		FOR(i,1,n)FOR(j,1,n)G[i][j]=(i!=j)*inf;
		FOR(i,1,n){
			int k,x;ll val;k=read();
			while(k--){
				x=read();val=read();
//				scanf("%d%lld",&x,&val);
				add(x,i,val);
			}
		}
		floyd();
		while(q--){
			int x,y;
//			scanf("%d%d",&x,&y);
			x=read();y=read();
			printf("%lld\n",query(x,y));
		}
		return 0;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	mycode::main();
	return 0;
}
