#include <bits/stdc++.h>
using namespace std;
int a[500100],d[10100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
	for(int i=1;i<=n;i++){
		int b[10100]={0},c[10010]={0};
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=j; 
				c[a[j]]+=1;
			}
			else{
				
				for(int k=b[a[j]];k<j;k++){
					c[a[k]]=0;
				}
				b[a[j]]=j;
				c[a[j]]+=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]!=0) d[j]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",d[i]);
	}
	return 0;
}
