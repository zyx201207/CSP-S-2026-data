//GZ-S00340 遵义市第一中学 胡明轩
#include <bits/stdc++.h>
using namespace std;
struct rode{
	int a,v;
}r[10086];
int c,n,m,d,q,w[500005],tmp,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		for(int j=1;j<=tmp;j++)scanf("%d %d",&r[i].a,&r[i].v);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


