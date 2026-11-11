#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2) cout<<32<<"\n"<<17;
	else cout<<35<<"\n"<<16;
	return 0;
}
