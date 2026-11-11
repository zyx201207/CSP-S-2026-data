#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				for(int k=f[a[j]];k<j;k++){
					f[a[k]]=0;
				}
			}
			f[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(f[j]!=0)b[j]++;
			f[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",b[i]);
	}
	return 0;
}
