//GZ-J0027 张蔚远 贵阳白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		int b[500005],z=0;
		for(int j=i;j<=n;j++){
			int pd=0;
			for(int k=1;k<=z;k++){
				if(a[j]==b[k]){
					pd=1;
					z=k;
					break;
				}
			}
			if(pd==0){
				z++;
				b[z]=a[j];
			}
		} 
		for(int j=1;j<=z;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]); 
	} 
	return 0;
}

