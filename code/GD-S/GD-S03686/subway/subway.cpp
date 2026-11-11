#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
int g[500005][3];
signed gl[501005],top,ttop;
int gg[505][505];
inline int MIn(int a,int b){
	return a<b?a:b;
}
inline void add(signed x,signed y,int z){
	g[++top][0]=y;
	g[top][1]=gl[x];
	gl[x]=top;
	g[top][2]=z;
}
inline void pt(int x){
	short a[20],t=0;
	while(x){
		a[++t]=x%10;
		x/=10;
	}
	while(t){
		putchar(a[t]+'0');
		t--;
	}
	putchar('\n');
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	signed C,N,M,D,Q;
	scanf("%d %d %d %d %d",&C,&N,&M,&D,&Q);
	const signed n=N;
	const signed m=M;
	const signed q=Q;
	ttop=m;
	for(signed i=1;i<=m;++i){
		scanf("%lld",&w[i]);
	}
	signed k,T;
	int W;
	for(signed i=1;i<=n;++i){
		scanf("%d",&k);
		++ttop;
		for(signed j=1;j<=k;++j){
			scanf("%d %lld",&T,&W);
			add(T,ttop,W);
		}
	}
	for(signed i=1;i<=n;++i){
		for(signed j=i;j<=n;++j){
			gg[i][j]=gg[j][i]=((int)1000000000000000);
		}
	}
	for(signed i=1;i<=m;++i){
		for(signed j=gl[i];j;j=g[j][1]){
			for(signed k=gl[i];k;k=g[k][1]){
				gg[g[j][0]-m][g[k][0]-m]=gg[g[k][0]-m][g[j][0]-m]=g[j][2]+g[k][2];
			}
		}
	}
	for(int i=1;i<=n;++i) gg[i][i]=0;
	for(signed k=1;k<=n;++k){
		for(signed i=1;i<=n;++i){
			for(signed j=i+1;j<=n;++j){
				gg[i][j]=gg[j][i]=min(gg[i][j],gg[i][k]+gg[k][j]);
			}
		}
	}
	int ans;
	for(signed i=1,x,y;i<=q;++i){
		scanf("%d %d",&x,&y);
		ans=LONG_LONG_MAX;
		for(signed j=gl[x];j;j=g[j][1]){
			for(signed k=gl[y];k;k=g[k][1]){
				ans=min(ans,gg[g[j][0]-m][g[k][0]-m]+g[j][2]+g[k][2]);
			}
		}
		pt(ans+w[x]+w[y]);
	}
}
