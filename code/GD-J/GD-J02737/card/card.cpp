#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int c[500005];

int main(){
	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		c[i]=n;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int k=1;k<=i;k++){
			for(int j=i;j>=1;j--){
				if(a[i]!=a[j]){
					c[a[j]]--;
				}
				else
					break;
			}
		}
		
	}
	for(int j=1;j<=m;j++){
		printf("%d ",c[j]);
	}
	
	
}
