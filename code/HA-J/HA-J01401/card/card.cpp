#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
long long cad[1000010],tabl[1000010];
long long flag[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&cad[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int q=1;q<sum;q++){
				if(tabl[q]==cad[j]){
					sum=q;
					break;
				}
			}
			tabl[sum]=cad[j];
			sum++;
		}
		for(int j=1;j<sum;j++) flag[tabl[j]]++;
		sum=1;
	}
	for(int i=1;i<=m;i++) printf("%lld ",flag[i]);
	return 0;
} 

