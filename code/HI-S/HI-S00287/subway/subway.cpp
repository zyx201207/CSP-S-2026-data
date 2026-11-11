#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define N 500010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue
#define pii pair<ll,ll >
#define fi first
#define se second

using namespace std;
const ll inf=1e18;
ll dis[510][510];
pii b[N][21];
int sz[N];
int a[N];
int n,m,q;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}  


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	For(i,1,m) a[i]=read();
	For(i,1,n){
		For(j,1,n){
			dis[i][j]=inf;
		}
	}
	For(i,1,n) dis[i][i]=0;
	For(i,1,n){
		int u=read();
		For(j,1,u){
			int v=read(),w=read();
			b[v][++sz[v]]=mk(i,w);
		}
	}
	For(i,1,m){
		For(j,1,sz[i]){
			For(k,j,sz[i]){
				int u=b[i][j].fi,v=b[i][k].fi;
				ll w=b[i][j].se+b[i][k].se;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			} 
		}
	}
	For(k,1,n){
		For(i,1,n){
			For(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			} 
		}
	}
	while(q--){
		int x=read(),y=read();
		ll ans=inf;
		For(i,1,sz[x]){
			For(j,1,sz[y]){
				int u=b[x][i].fi,v=b[y][j].fi;
				ans=min(ans,dis[u][v]+b[x][i].se+b[y][j].se+a[x]+a[y]);
			} 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
