#include <bits/stdc++.h>
using namespace std;
int a[500001],type[300001];
int b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=i;j<=n;j++){
			for(int l=0;l<k;l++){
				if(b[l]!=a[j]) continue;
				k=l; break;
			}
			b[k]=a[j]; k++;
		}
		for(int j=0;j<k;j++) type[b[j]]++;
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++) printf("%d ",type[i]);
	return 0;
}
