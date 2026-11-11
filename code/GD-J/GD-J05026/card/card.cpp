#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[500008],a[500008];
int ans[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		int cnt=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					cnt=k-1;
				}
			}
			b[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
