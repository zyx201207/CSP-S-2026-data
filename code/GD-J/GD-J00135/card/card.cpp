#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sl[500005],bc[500005],k,wz[500005],pd=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1])
			pd=0;
	}
	if(pd==1){
		a[0]=a[1];
		for(long long i=1;i<=n;i++)
			sl[a[i]]=i;
		for(int i=1;i<=m;i++)
			printf("%lld ",sl[i]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			bc[++k]=a[j];
			if(wz[a[j]]==0)
				wz[a[j]]=j;
			else{
				k=wz[a[j]];
				for(int z=1;z<=m;z++)
					if(wz[z]>k)
						wz[z]=0;
			}
		}
		for(int j=1;j<=m;j++){
			if(wz[j]>0)
				sl[j]++;
			wz[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",sl[i]);
	return 0;
} 
