#include<iostream>
#include<cmath>
using namespace std;
int m,n,a[1000],b[1000],c[1000],k,o=1; 
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	//freopen("card.in",'r',stdin);
	//freopen("card.out",'w',stdout);
	for(int i=1;i<=m;i++){
		b[i]=i;
	}
	for(int j=m;j>=1;j--){
		for(int k=j-1;k>=1;k--){
			if(a[k]==a[j]){
				for(int p=k;p<j;p++){
					b[p]--;
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		c[a[k]]+=b[k]; 
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<' '; 
	}
	return 0;
}
