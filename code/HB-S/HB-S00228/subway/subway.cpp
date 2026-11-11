#include<bits/stdc++.h>
using namespace std;
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int t[m+5][n+5],k,x,y,bl[m+5][d+5];
	long long ans,w[m+5];
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
		bl[i][0]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			t[x][i]=y;
			bl[x][0]++,bl[x][bl[x][0]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=bl[i][0];j++){
			for(int k=1;k<=bl[i][0];k++){
				if(j==k) continue;
				f[bl[i][j]][bl[i][k]]=t[i][bl[i][j]]+t[i][bl[i][k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) f[i][j]=0;
			else if(f[i][j]==0) f[i][j]=100000000005;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		ans=LONG_LONG_MAX;
		for(int j=1;j<=bl[x][0];j++){
			for(int k=1;k<=bl[y][0];k++){
				long long tmp=t[x][bl[x][j]]+t[y][bl[y][k]];
				ans=min(ans,f[bl[x][j]][bl[y][k]]+tmp);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
