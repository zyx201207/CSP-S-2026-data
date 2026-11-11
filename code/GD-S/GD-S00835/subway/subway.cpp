#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
const ll N=1005,M=1e6+5;
ll C,n,m,d,QQQ,w[M],len[N];
vector<ll> a[N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),QQQ=read();
	For(i,1,m)w[i]=read();
	For(i,1,n){
		len[i]=read();
		a[i].pb(-1),t[i].pb(-1);
		For(j,1,len[i])a[i].pb(read()),t[i].pb(read());
	}
	if(C<=11){
		vector<vector<ll>> d(m+1,vector<ll>(m+1,1e18));
		For(i,1,m)d[i][i]=0;
		For(i,1,n){
			For(x,1,len[i]){
				For(y,x+1,len[i]){
					ll u=a[i][x],v=a[i][y],w=t[i][x]+t[i][y];
					d[u][v]=d[v][u]=min(d[u][v],w);
				}
			}
		}
		For(k,1,m){
			For(i,1,m){
				For(j,i+1,m){
					d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		while(QQQ--){
			ll u=read(),v=read();
			printf("%lld\n",d[u][v]+w[u]+w[v]);
		}
		return 0;
	}
	if(C>=12 && C<=19){
		ll T=0;
		vector<vector<bool> > Wayming(n+1,vector<bool>(m+1,0));
		vector<vector<ll> > d(n+1,vector<ll>(n+1,1e18));
		vector<vector<ll> > in(m+1);
		For(i,1,n){
			d[i][i]=0;
			For(j,1,len[i]){
				T=t[i][j]*2;
				in[a[i][j]].pb(i);
				Wayming[i][a[i][j]]=1;
			}
		}
		For(i,1,m){
			for(auto x:in[i]){
				for(auto y:in[i]){
					d[x][y]=min(d[x][y],1ll);
				}
			}
		}
		For(k,1,n){
			For(i,1,n){
				For(j,i+1,n){
					d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		while(QQQ--){
			ll u=read(),v=read();
			bool f=0;
			For(i,1,n){
				if(Wayming[i][u] && Wayming[i][v]){
					f=1;
					break;
				}
			}
			if(f){
				printf("%lld\n",T+w[u]+w[v]);
				continue;
			}
			ll res=1e18;
			for(auto x:in[u]){
				for(auto y:in[v]){
					res=min(res,d[x][y]*T);
				}
			}
			printf("%lld\n",T+res+w[u]+w[v]);
		}
		return 0;
	}
	return 0;
}

