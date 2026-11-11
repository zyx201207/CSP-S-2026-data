#include <bits/stdc++.h>
using namespace std;
int a[500015],num[500015];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int c[m];
		for(int j=i-1;j<=n;j++){
			c[j]=a[j];
			bool bl=true;
			for(int l=i-1;l<=j-1;l++){
				if(c[j]==c[l]){
					bl=false;
				}
				if(bl==true){
					c[j]=-1;
				}
			}
		}
		for(int j=i-1;j<=n;j++){
			if(c[j]!=-1){
				num[c[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	} 
	return 0;
} 
