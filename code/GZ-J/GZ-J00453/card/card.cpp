//GZ-J00453 ¹ùÓê³¿ 
#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[700000],f[700000],b[700000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		for(int z=1;z<=n;z++) b[z]=a[z]; 
		for(int j=i+1;j<=n;j++){
			for(int z=j;z>=i+1;z--){
				if(b[z]==b[j]){
					for(int y=z;y<=j-1;y++){
						b[y]=0;
					}
				}
			}
		}
		for(int j=i+1;j<=n;j++){
			if(b[j]!=0) f[j]++;
		}
	}
	for(int i=n;i>=1;i--){
		if(f[i]!=0) 
		cout<<f[i]<<' ';
	}
	return 0;
}
