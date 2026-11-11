#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;bool w=0;char c=getchar();
	while(c<'0'||c>'9')  c=='-'?w=1:0,c=getchar();
	while(c>='0'&&c<='9')  x=x*10+(c-48),c=getchar();
	return w?-x:x;
}
const int N=505,M=5e5+5;
vector<pair<int,int>> sbw[M];
int TC,n,m,d,q,a[M],dis[N][N];
inline void ckmn(int &a,int b){a>b?a=b:0;}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	TC=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)  a[i]=rd();
	for(int i=1;i<=n;i++){
		for(int j=1,k=rd();j<=k;j++){
			int a=rd(),t=rd();
			sbw[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int len=sbw[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				ckmn(dis[sbw[i][j].first][sbw[i][k].first],sbw[i][j].second+sbw[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ckmn(dis[i][j],dis[j][i]),
			ckmn(dis[j][i],dis[i][j]);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)if(i!=k){
			for(int j=1;j<=n;j++)if(i!=j&&j!=k){
				ckmn(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=rd(),y=rd(),ans=1e18;
		int lx=sbw[x].size(),ly=sbw[y].size();
		for(int i=0;i<lx;i++){
			for(int j=0;j<ly;j++){
				ckmn(ans,sbw[x][i].second+sbw[y][j].second+dis[sbw[x][i].first][sbw[y][j].first]);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
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
// 华风夏韵，洛水天依
