#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],ans[300007],p[500007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int r=0;
		for(int j=i;j<=n;j++){
			p[++r]=a[j];
			for(int k=1;k<=r-1;k++){
				
				if(p[k]==p[r]){
					r=k;
					break;
				}
			}
			
		}
		for(int j=1;j<=r;j++){
			ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

