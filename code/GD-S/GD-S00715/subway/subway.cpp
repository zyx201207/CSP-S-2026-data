#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int c,n,m,d,q,w[250005],k[505],a[505][500005];
int t[505][505],way[505],sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int ke=0,T=0;
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		if(k[i]>2) ke=1;
		for (int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(t[i][j]!=t[i][j-1]) T=1;
			way[a[i][j]]++;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	return 0;
}
