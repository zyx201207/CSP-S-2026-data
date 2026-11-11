#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],t[300010];

int main(){
	freopen("card.in","in",stdin);
	freopen("card.out","out",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int k=j+1;k<=n;k++){
				if(a[k]==a[j]){
					j=k-1; flag=1;
					break;
				}
			}
			if(flag==0) t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",t[i]);
	return 0;
}
