#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l,k,b[500005],x[500005],x1[500005],p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		k=i;l=1;
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(x));
		while(k<=n){
			p=0;
			b[l]=a[k];
			x[a[k]]++;
			if(x[a[k]]==2){
				for(int j=1;j<=l;j++){
					if(b[j]==a[k]){
						p++;
						if(p==2){
							break;
						}
					}
					if(p==1){
						x[b[j]]--;
						b[j]=0;
					}
				}
			}
			k++;
			l++;
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0)x1[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",x1[i]);
	return 0;
}
