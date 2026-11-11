#include<bits/stdc++.h>
using namespace std;
int a[300009],b[500009],c[500009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i];
//	}
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++){
			c[j]=0;
		}
		for(int j=1+i;j<=n;j++){
			c[j]=b[j];
			if(j!=i+1){
				bool fg=0;
				for(int k=1+i;k<=j;k++){
					if(fg){
						c[j]=0;
						c[k]=0;
					}
					if(c[j]==c[k]){
						fg=1;
					}
				}
			}
		}
//		for(int j=1+i;j<=n;j++){
//			cout<<c[i]<<" ";
//			
//		}
//		for(int j=1+i;j<=n;j++){
//			cout<<b[i]<<" ";
//			
//		}
//		cout<<endl;
		for(int j=1+i;j<=n;j++){
			if(c[i])a[c[i]]+=1;
		}
	}
	for(int i=1;i<=300002;i++){
		if(a[i]){
			cout<<i;
			cout<<a[i]<<" ";
		}
	}
}
