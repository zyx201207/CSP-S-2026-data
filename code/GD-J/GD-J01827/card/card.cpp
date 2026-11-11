#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int a[n],b[n];
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int f[n];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int x=0;x<=j;x++){
				if(f[x]==a[j]){
					for(int y=x+1;y<=n;y++){
						f[y]=0;
					}
					break;}
				else f[j]=a[j];
				
			}
			
		}
		for(int q=0;q<n;q++){
			for(int p=1;p<=m;p++){
				if(f[q]==p){
				b[p]+=1;
				}
			}
		}
	}
	for(int z=1;z<=m;z++){
		cout<<b[z]<<' ';
	}
	return 0;
} 
