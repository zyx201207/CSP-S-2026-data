#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005][3],ans[300005],las[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		a[i][1]=las[a[i][0]];
		las[a[i][0]]=i;
	}
	for(int i=1;i<=n;i++){
		a[i][2]=las[a[i][0]];
	}
	for(int i=1;i<=m;i++){
		a[las[i]][2]=n+1;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&j){
			if(a[j][2]>n){
				ans[a[j][0]]++;
				j++;
			}
			else j=a[j][2];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
