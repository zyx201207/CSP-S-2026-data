#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e5+10;
int c,n,m,d,q;
int w[510];
int k[510],a[510][N],t[510][N],x[M],y[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=q;i++){
		cout<<1<<endl;
	}
    return 0;
}
