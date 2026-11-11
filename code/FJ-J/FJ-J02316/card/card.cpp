#include<stdio.h> 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long nn,n,m,a[500005],tl[300005],b[500005],lr;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		nn=n;
		for(int j=i;j<=n;j++){
			lr=lower_bound(a+i,a+nn+1,b[j])-a;
			if(a[lr]==b[j]){
				nn=lr;
			}else{
				nn++;
				a[nn]=b[j];
			}
		}
		for(int j=1;j<=m;j++){
			if(a[lower_bound(a+i,a+nn+1,j)-a]==j){
				tl[j]++;
			}
		}
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",tl[i]);
	}
	return 0;
}
