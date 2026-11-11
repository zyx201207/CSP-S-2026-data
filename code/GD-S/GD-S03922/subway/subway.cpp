#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=505;
int c,n,m,d,q;
int t[N];
struct site{
	int id;
	int w;
};
vector<site> s[N];
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&t[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,w;
			scanf("%lld%lld",&a,&w);
			s[a].push_back({i,w});
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=LONG_LONG_MAX;
		}
		f[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<s[k].size();i++){
			int u=s[k][i].id,w1=s[k][i].w;
			for(int j=i+1;j<s[k].size();j++){
				int v=s[k][j].id,w2=s[k][j].w;
//				printf("%lld %lld\n",u,v);
				f[u][v]=min(f[u][v],w1+w2);
				f[v][u]=min(f[v][u],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=LONG_LONG_MAX;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				int u=s[x][i].id,v=s[y][j].id;
				int w1=s[x][i].w,w2=s[y][j].w;
//				printf("%lld %lld %lld \n",u,v,f[u][v]+w1+w2);
				ans=min(ans,f[u][v]+w1+w2);
			}
		}
		printf("%lld\n",ans+t[x]+t[y]);
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

35
16

35
20

*/
