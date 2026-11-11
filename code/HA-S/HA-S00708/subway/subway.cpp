#include<bits/stdc++.h>
using namespace std;
int n,k[500010],c,q,d,m,w[500010],sum,a[500010],t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[j],&t[j]);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y-x==1)cout<<w[x]+w[y]+2*t[1]<<endl;
		else cout<<w[x]+w[y]+(y-x)*t[1]+2*t[1]<<endl;
	}
	return 0;
}
