#include<bits/stdc++.h>
using namespace std;
int n,a[500001],table[500001],cnt[500001],m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(table,0,sizeof table);
		for(int j=i;j<=n;j++){
			table[j]=a[j];
			for(int k=1;k<=j-1;k++){
				if(table[j]==table[k]){
					for(int l=0;l<=k-1;l++)
						table[l]=0;
				}
				table[k]=a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			if(table[j]!=0)
				cnt[i]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",cnt[i]);
	return 0;
}
