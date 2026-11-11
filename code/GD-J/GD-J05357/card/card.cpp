#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,a[N],m,d[N],dn,dl,ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dl=-1;
			for(int k=1;k<=dn;k++){
				if(d[k]==a[j]){
					dl=k;
					break;
				}
			}
			if(dl!=-1){
				for(int k=dl;k<=dn;k++){
					d[k]=-1;
				}
				dn=dl-1;
			}
			dn++;
			d[dn]=a[j];
		}
		for(int j=1;j<=dn;j++){
			ans[d[j]]++;
			d[j]=-1;
		}
		dn=0;
	}
	sort(a+1,a+1+n);
	unique(a+1,a+1+n);
	for(int i=1;i<=m;i++){
//		cout<<a[i]<<" ";
		printf("%lld ",ans[a[i]]);
	}
	return 0;
}/*
4 3 
1 2 1 3

*/
