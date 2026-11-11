#include<bits/stdc++.h>
using namespace std;
int n,m,k,i;
int a[10000005];
int ans[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",n,m);
	for(int x=0;x<n;x++){
		scanf("%d",a[x]);
	}
	for(int u=0;u<m;u++){
		ans[u]=n;
		for(int o=0;o<n;o++){
			for(int e=0;e<n;e++){
				if(a[o]==a[e]){
					ans[u]=ans[u]-(e-o);
				}
			}
		}
	}
	for(int p=0;p<m;p++){
		printf("%d",ans[p]);
	}
	return 0;
}
