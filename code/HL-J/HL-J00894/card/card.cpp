#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[500010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int z=0;
		for(int j=i;j<=n;j++){
			int p=a[j];
			if(d[p]==0) z++;
			else{
				for(int k=d[p]+1;k<=z;k++){
					d[c[k]]=0;
				}
				z=d[p];
			}
			c[z]=p;
			d[p]=z;
		}
		for(int j=0;j<=n;j++){
			if(j<=m) d[j]=0;
			if(j<=z){
				b[c[j]]++;
			}
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
}