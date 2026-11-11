#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define inf 1000000000000000000
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int const M=500501,N=551;
int c,n,m,d,q;
ll w[M],e[N][N];
vector<pii>a[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)e[i][j]=0;
			else e[i][j]=inf;
		}
	}for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,aa,tt;j<=k;j++){
			bool bo=1;
			scanf("%d%d",&aa,&tt);
			for(auto &o:a[aa]){
				int u=o.F;
				if(u==i){
					o.S=min(o.S,tt);
					bo=0;
					continue;
				}e[i][u]=min(e[i][u],(ll)o.S+tt);
				e[u][i]=e[i][u];
			}if(bo)a[aa].PB({i,tt});
		}
	}for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++)
			e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	}for(int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		ll res=inf;
		for(auto o1:a[u])for(auto o2:a[v]){
				res=min(res,o1.S+o2.S+e[o1.F][o2.F]);
		}printf("%lld\n",w[u]+w[v]+res);
	}return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2




0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
