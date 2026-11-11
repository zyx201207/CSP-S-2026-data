#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[1000005],c[300005],x[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[a[i]]=i;
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(d[a[j]]!=j){
				j=d[a[j]]-1;
				continue;
			}
			else{
				x[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			c[j]+=x[j];
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",c[i]);
	}
	return 0;
}
