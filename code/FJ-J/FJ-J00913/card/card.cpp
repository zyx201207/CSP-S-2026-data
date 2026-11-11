#include<bits/stdc++.h>
using namespace std;
int n,m,a[300030],v[300030],k[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(j==v[a[j]]){
				k[a[j]]++;
				j++;
			}else{
				j=v[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",k[i]);
	return 0;
}
