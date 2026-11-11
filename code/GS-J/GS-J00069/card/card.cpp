#include<bits/stdc++.h>
using namespace std;

int n,m,a[10001],top=0,near=0;
int b[100001],sum[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			for(int j=near;j<=top;j++){
				if(b[j]==a[i]){
					near=top;
				}
			}
		b[++top] = a[i];
		}
		for(int i=near;i<=top;i++)
		 	sum[b[i]]++;
	}  
	for(int i=1;i<=m-1;i++)
		printf("%d ",sum[i]);
	sum[m] -=1;
	printf("%d",sum[m]);
	return 0;
}
