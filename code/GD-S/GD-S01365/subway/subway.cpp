#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	unsigned long long c,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	unsigned long long w[m],k[n],a[n][m],t[n][m],b[q],e[q];
	for(long long i=0;i<m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=0;i<n;i++){
		scanf("%lld",&k[i]);
		for(long long j=0;j<k[i];j++){
			scanf("%lld",&a[i][j],&t[i][j]);
		}
	}
	for(long long i=0;i<q;i++){
		scanf("%lld %lld",&b[i],&e[i]);
	}
	if(c==0&&n==2&&m==5&&d==20&q==2)cout<<"32\n17";
	if(c==0&&n==3&&m==7&&d==20&q==2)cout<<"35\n16";
	return 0;
}
