#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],out=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==1){
			if(out<a[i]){
				out=a[i];
			}
		}
		
	}
	if(m==n){
		out=a[0]&a[1];
		for(int i=2;i<n;i++){
			out=out&a[i];
		}
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(out<(a[i]&a[j])){
					out=a[i]&a[j];
				}
			}
		}
	}
	if(m==3){
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(out<(a[i]&a[j]&a[k])){
						out=a[i]&a[j]&a[k];
					}
				}
				
			}
		}
	}
	if(m==4){
		for(int i=0;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int x=k+1;x<n;x++){
						if(out<(a[i]&a[j]&a[k]&a[x])){
							out=a[i]&a[j]&a[k]&a[x];
						}	
					}
					
				}
				
			}
		}
	}
	if(m==5){
		for(int i=0;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int x=k+1;x<n-1;x++){
						for(int y=x+1;y<n;y++){
							if(out<(a[i]&a[j]&a[k]&a[x]&a[y])){
								out=a[i]&a[j]&a[k]&a[x]&a[y];
							}	
						}
							
					}
					
				}
				
			}
		}
	}
	cout<<out; 
	return 0;
}
