#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int a[100005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	int b[100005]={0};
	for(int q=0;q<n;q++){
		
		
		
		
		
		
		
		
		int c[100005]={0};
		for(int i=q;i<n;i++){
			c[i]=a[i];
		
			for(int j=0;j<i;j++){
				if(c[j]==a[i]){
					for(;j<i;j++){
						c[j]=0;	
					
				}	
			}
		}
		
		}
		for(int y=0;y<n;y++){
			if(c[y]!=0){
				b[a[y]]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

