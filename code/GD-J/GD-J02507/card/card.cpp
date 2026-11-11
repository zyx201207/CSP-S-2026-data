#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],r,x[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(x,0,sizeof(x));
		r=0;
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0){
				r++;
				c[r]=a[j];
				x[a[j]]=r;
			}else{
				for(int k=x[a[j]]+1;k<=r;k++){
					x[c[k]]=0;
					c[k]=0;
				}
				r=x[a[j]];
			}
		}
		for(int j=1;j<=r;j++){
			b[c[j]]++;
		}
	}
	printf("%d",b[1]);
	for(int i=2;i<=m;i++){
		printf(" %d",b[i]);
	}
	printf("\n");
	return 0;
}
