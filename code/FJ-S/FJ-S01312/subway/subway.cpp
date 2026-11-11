#include<bits/stdc++.h>
#define N 500005
#define rep(i,a,b)     for(int i=(a);i<=(b);i++)
#define int long long
using namespace std;
int c,n,m,d,q,w[N],t[N],dis[1000][1000];
struct node{
	int v,w;
}s[N][22];
signed main(){
	   ios::sync_with_stdio(0);
	   cin.tie(0);
	   freopen("subway.in","r",stdin);
	   freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)	cin>>w[i];
	rep(i,1,n){
		int k,a,qwq;
		cin>>k;
		rep(j,1,k)	cin>>a>>qwq,s[a][++t[a]]={i,qwq};
	}
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n)	dis[i][i]=0;
	rep(i,1,m){
		rep(j,1,t[i]){
			rep(k,j+1,t[i])	dis[s[i][j].v][s[i][k].v]=dis[s[i][k].v][s[i][j].v]=min(dis[s[i][j].v][s[i][k].v],s[i][j].w+s[i][k].w);
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			rep(k,1,n)	dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		}
	}
	rep(i,1,q){
		int x,y,ans=1e18;
		cin>>x>>y;
		rep(j,1,t[x])
			rep(k,1,t[y])	ans=min(ans,dis[s[x][j].v][s[y][k].v]+s[x][j].w+s[y][k].w);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}

