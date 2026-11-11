#include <bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,Q=1e5+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
bool A,B;
int T=-1,ma=0;
long long int solveA(int x,int y){
	long long int sum=0;
	while(x!=y){
		sum+=w[x];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					sum+=t[i][j];
					if(j==1)x=a[i][2];
					else x=a[i][3];
				}
				if(x==y){
					sum+=w[y];
					return sum;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		ma=max(ma,k[i]);
		if(ma>2)A=true;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(T==-1)T=t[i][j];
			if(T!=t[i][j])B=true;
		}
	}int x[Q],y[Q];
	for(int i=1;i<=q;i++)scanf("%d",&x[i],y[i]);
	for(int i=1;i<=q;i++){
		long long int ans=solveA(x[i],y[i]);
		printf("%lld\n",&ans);
	}
	

	return 0;
}
