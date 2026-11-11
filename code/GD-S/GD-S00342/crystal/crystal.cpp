#include <bits/stdc++.h>
using namespace std;
int change=0;
int b[99999];
int x=1000000;
int xb=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++){	
		cin>>a[i];
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]<a[j]){
				change=a[i];
				a[i]=a[j];
				a[j]=change;
			}
		}
	}
	for(int i=0;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=0;i<n;i++){
		if(x>b[i]){
			x=b[i];
			xb=i;
		}
	}
		for(int j=0+xb;j<=m+xb;j++){
			if(m>=0){
				
						
				while(a[j]!=a[j+1]){
					a[j]++;
					m--;
					}
				a[j+1]*=2;
				
			for(int l=j+1;l<n;l++){
				for(int r=j+1;r<n;r++){
					if(a[l]<a[r]){
						change=a[l];
						a[l]=a[r];
						a[r]=change;
					}
				}
			}
			
			}
			if(m<=0) cout<<j;
			
		
		}
		
	return 0;
} 
