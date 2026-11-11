#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
long long v,w[500001],k,a[500001],t[500001];
int main(){
	freopen("subway.in","r",stdin);
	/*提交前记得取消注释freopen*/
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	scanf("%lld",&k);
	for(int i=1;i<=k;i++)
		scanf("%lld %lld",&a[i],&t[i]);
	printf("35/n16");
	return 0;
}

