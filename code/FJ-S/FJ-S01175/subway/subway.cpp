#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+5,MAXV=505;
typedef long long ll;
typedef pair<ll,ll> pii;
#define fi first
#define se second
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define rrep(x,y,z) for(int x=z;x>=y;x--)
#define anti printf("line %d ok\n",__LINE__);fflush(stdout);
const ll inf=1e18;


/*
lines as Vetrex,stations as edges
if both line i and line j goes to station k,there's an edge between vetrex i and vetrex j
then do floyd?
*/

//15:54 A pretty BruteForce,Chtholly bless me,hope C's device can do 2e10
//15:56 who F touch my powerline?It really scared me,but my code is still here
//16:56 meet unknown error,Da Biao Guo Yang li
//18:07 How stupid I!scanf should &x!

//"Though we'll be funky,I'll ban you first"---kkksc03

int n,m,q,w[MAXN];
ll dist[MAXV][MAXV];
int t[MAXN][MAXV];
int a[MAXN][MAXV];

void build(){
	memset(dist,0x3f,sizeof dist);
	rep(k,1,m){
		rep(i,1,a[k][0]){
			rep(j,1,a[k][0]){
				int u=a[k][i],v=a[k][j];
				if(dist[u][v]>t[k][u]+t[k][v]){
					dist[u][v]=t[k][u]+t[k][v];
				}
				dist[u][v]*=int(u!=v);
			}
		}
	}
}

void floyd(){
	rep(k,1,n)rep(i,1,n)rep(j,1,n){
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
}

void solve(){
	ll res=inf;
	int u,v;
	scanf("%d %d",&u,&v);
	rep(i,1,a[u][0]){
		rep(j,1,a[v][0]){
			int p=a[u][i],q=a[v][j];
			res=min(res,dist[p][q]+t[v][q]+t[u][p]);
		}
	}
	printf("%lld\n",res+w[u]+w[v]);
}

int main(){
	#ifndef off
	qwq("subway");
	#endif
	
	scanf("%*d %d %d %*d %d",&n,&m,&q);
	rep(i,1,m)scanf("%d",w+i);
	
	rep(i,1,n){
		int k;
		scanf("%d",&k);
		rep(j,1,k){
			int v,ww;
			scanf("%d %d",&v,&ww);
			t[v][i]=ww;
			a[v][++a[v][0]]=i;
		}
	}
	
	build();
	floyd();
	
	while(q--)solve();
}
