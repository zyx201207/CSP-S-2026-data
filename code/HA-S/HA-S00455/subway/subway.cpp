#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=505,M=1005;
int n,c,m,d,q;
ll w[M],b,a[N][M],t[N][M];
ll ans[M][M],an[N][N];
int fa[M];
vector<int>xian[M];
int getf(int k){
	if(fa[k]==k)return fa[k];
	return fa[k]=getf(fa[k]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);fa[i]=i;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i==j)an[i][j]=0;else an[i][j]=1e18;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&b,&t[i][j]);
			a[i][b]=t[i][j];xian[b].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[j][i]==0||a[k][i]==0)continue;
				an[j][k]=an[k][j]=min(an[j][k],a[j][i]+a[k][i]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ll minn=1e18,xu=1e18;
		for(int j=0;j<(int)xian[x].size();j++){
			for(int k=0;k<(int)xian[y].size();k++){
			//	cout<<xian[x][j]<<" "<<xian[y][k]<<"-"<<endl;
				if(an[xian[x][j]][xian[y][k]]<=minn){
					minn=an[xian[x][j]][xian[y][k]];
					xu=a[xian[x][j]][x]+a[xian[y][k]][y];
				}
			}
		}
	//	cout<<minn<<" ";
		printf("%lld\n",minn+w[x]+w[y]+xu);
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			if(i==j)continue;
//			for(int k=1;k<=m;k++){
//				if(k==i)
//			}
//		}
//	}
	
	
/*
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
	
	return 0;
} 
