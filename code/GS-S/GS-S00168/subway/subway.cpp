#include<bits/stdc++.h>
using namespace std;
int c,d,n,m,q,w[500005],a[505][500005],t[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	while(q--){
		int x,y,ans=w[x]+w[y];
		scanf("%d%d",&x,&y);
		printf("%d\n",q);
	}
	return 0;
}
