#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=n;k>=j;k--){
				if(a[k]==a[j]){
					j=k;
					ans[a[k]]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
