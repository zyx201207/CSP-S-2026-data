#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int b[N];
int c[N];
int s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==m){
		for(int i=1;i<=n;i++)
		{
			printf("%d ",i);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			c[b[j]]++;
			if(c[b[j]]>1){
				for(int k=j-1;k>=1;k--){
					if(b[k]!=b[j]){
						c[b[k]]--;
						b[k]=0;
					}
					else{
					    c[b[j]]--;
					    b[j]=0;
					    k=1;
					}
				}
			}
			
		}
		for(int k=i;k<=n;k++){
					s[b[k]]++;
				}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
}
