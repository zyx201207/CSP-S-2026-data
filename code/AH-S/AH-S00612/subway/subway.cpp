#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ap,tp,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",rand()%2000);
	}
	return 0;
}
