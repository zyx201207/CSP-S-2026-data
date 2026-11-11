#include<bits/stdc++.h>
using namespace std;
int n,m,a[500009],aa[500009],b[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++){
			aa[j]=a[j];
			if(b[aa[j]]==1){
				for(int k=j-1;k<=0;k--){
					b[aa[k]]=0;
					if(b[aa[j]]==0){
						break;
					}
				}
				b[aa[j]]=1;
			}
		}
	}
	for(int i=i;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
