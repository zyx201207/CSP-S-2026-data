#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001]={0},zm[500001]={0},pa[500001]={0},z=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int y=0,k=1;
			for(k=1;k<=z;k++){
				if(zm[k]==a[j]){
					y=1;
					break;
				}
			}
			if(y==0){
				zm[++z]=a[j];
			}else{
				z=k;
				zm[z]=a[j];
			}
		}
		for(int j=1;j<=z;j++){
			pa[zm[j]]++;
		}
		z=0;
	}
	for(int i=1;i<=m;i++){
		cout<<pa[i]<<" ";
	}
	return 0;
}
