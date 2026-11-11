#include<bits/stdc++.h>
using namespace std;
const int INF=1e9,MAXN=5010;

int a[MAXN],ans[MAXN],b[MAXN],f[MAXN][MAXN],d[MAXN][MAXN];
void work(int op){
	int n,dd;
	scanf("%d%d",&n,&dd);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int fl=0;
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=dd){
				f[i][j]=1;fl=1;
			}
		}
	}
	int nans=0;
	for(int lenth=2;lenth<=n;lenth++){
		for(int l=1;l+lenth-1<=n;l++){
			int r=l+lenth-1;
			for(int k=l+1;k<r;k++){
				if(f[l][r]>f[l][k]+f[k][r]){
					f[l][r]=f[l][k]+f[k][r];
				}else if(f[l][r]==f[l][k]+f[k][r]){
					d[l][r]++;
					if(d[l][r]==1) nans++;
					if(d[l][r]==2) nans--;
				}
			}
		}
	}
	ans[op]=nans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INF;
			d[i][j]=0;
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=1;i<=5000;i++)
	for(int j=1;j<=5000;j++) f[i][j]=INF;
	int c,t;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		work(i);
	}
	for(int i=1;i<=t;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
} 
