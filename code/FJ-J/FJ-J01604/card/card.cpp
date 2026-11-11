#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,maxn=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				if(a[i]>maxn){
					maxn=a[i];
				}
			}
		} 
	}
	printf("%lld",maxn);
	return 0;
} 
