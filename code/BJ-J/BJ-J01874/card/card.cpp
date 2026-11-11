#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int tx[300005],book[500005];
		for(int j=1;j<=m;j++)tx[j]=0;
		for(int j=1;j<=n;j++)book[j]=0;
		for(int j=i;j<=n;j++){
			tx[a[j]]++;
			if(tx[a[j]]>1){
				for(int k=1;k<j;k++){
					if(a[k]==a[j] && book[k]==0){
						for(int l=k;l<j;l++){
							if(book[l]==0){
								book[l]=1;
								tx[a[l]]--;
							}
						}
						break;
					}
				}
			}
		}
		for(int j=1;j<=m;j++)t[j]+=tx[j];
	}
	for(int i=1;i<=m;i++)printf("%d ",t[i]);
	return 0;
}
