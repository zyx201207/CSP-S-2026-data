//GZ-J00344  遵义市第十九中学 丁钧泽 
#include<bits/stdc++.h>
using namespace std;
int a[1000005],z[1000005],t[1000005],c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,x=0,y=0,f=0;
	while(i<=n){
		for(int j=i;j<=n;j++){
			 for(int k=1;k<=x;k++){
			 	if(a[j]==z[k]){
			 		f=k;
			 		break;
				 }
			 }
			 if(f!=0){
			 	while(x>=f){
			 		z[x]=0;
			 		x--;
				 }
			 }
			 f=0;
			x++;
			z[x]=a[j];
		}
		for(int j=1;j<=x;j++){
			t[z[j]]++;
		}
		for(int j=1;j<=x;j++){
			z[j]=0;
		}
		x=0;
		i++;
	}
	for(int j=1;j<=m;j++){
		cout<<t[j]<<" ";
	}
	return 0;
} 
