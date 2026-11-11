//GZ-S00428 陈则睿 贵阳实验三中 
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,tot;
long long w[1010];
long long f[5010][5010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}
	for(int i=0;i<5010;i++){
		for(int j=0;j<5010;j++){
			f[i][j]=100000000;
		}
	}
	for(int u=m+1;u<=n+m;u++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int v,ww;cin>>v>>ww;
			f[u][v]=ww,f[v][u]=ww;
		}
	}
	for(int q=1;q<=m+n;q++){
		for(int u=1;u<=m+n;u++){
			for(int v=1;v<=m+n;v++){
				f[u][v]=min(f[u][v],f[u][q]+f[q][v]);
			}
		}
	}
	while(q--){
		int x,y;scanf("%lld%lld",&x,&y);
		printf("%lld\n",f[x][y]+w[x]+w[y]);
	} 
	return 0;
} 
