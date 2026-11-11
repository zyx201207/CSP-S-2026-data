#include "bits/stdc++.h"
using namespace std;
int n,m,a[200005],b[200005],c[200005],ans[200005];
int main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	scanf ("%d %d",&n,&m);
	int flag=1;
	for (int i=1;i<=n;i++){
		scanf ("%d",&a[i]);
		if (i>=2){
			if (a[i]<a[i-1]) flag=0;
		}
	}
	if (flag){
		for (int i=1;i<=n;i++){
			if (a[i]!=a[i+1]){
				b[a[i]]=i;
			}
		}
		for (int i=1;i<=m;i++){
			printf ("%d ",b[i]);
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		memset (b,0,sizeof b);
		memset (c,0,sizeof c);
		int tot=0;
		for (int j=i;j<=n;j++){
			if (c[a[j]]==0 || c[a[j]]>tot) { 
				b[++tot]=a[j];
				c[a[j]]=tot;
			}
			else {
				tot=c[a[j]];
			}
		}
		for (int j=1;j<=tot;j++){
			ans[b[j]]++;
//			if (b[j]==3) printf ("%daa  ",i);
		}
	}
	for (int i=1;i<=m;i++){
		printf ("%d ",ans[i]);
	}
	return 0;
}
