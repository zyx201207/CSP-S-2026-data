#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],flag=1,d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
		d[a[i]]=i;
		if(a[i]<a[i-1]){
			 flag=0;
		}
	}
	if(flag==1){
		for(int i=1;i<=m;i++){
			printf("%d ",d[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(b[j]==b[k]){
					for(int l=k;l<j;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=0){
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[i]);
	}
	return 0;
}
