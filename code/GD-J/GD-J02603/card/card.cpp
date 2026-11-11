#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],z[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=0,k=1;
			for(;z[k]!=0;k++){
				if(a[j]==z[k]){
					f=1;
					for(int l=k+1;z[l]!=0;l++){
						z[l]=0;
					}
					break;
				}
			}
			if(!f){
				z[k]=a[j];
			}
		}
		for(int k=1;z[k]!=0;k++){
			b[z[k]]++;
			z[k]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
