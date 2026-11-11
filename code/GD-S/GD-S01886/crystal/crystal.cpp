#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    int s=0;
    for(int i=0;i<m;i++){
    	s=arr[i]+s;
	} 
	int z=s/m;
	int k;
	for(int i=0;i<n;i++){
		if(arr[i]==z){
			i=k;
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
	
		if(m=m-(z-arr[i])>0){
		
			sum=sum+1;
				m=m-(z-arr[i]);
		        
	}else{
			if(m=m-(z-arr[i])==0){
			sum=sum+1;
				m=m-(z-arr[i]);
		        sum=sum+1;
		        break;
	}
	}
	
		
		
		
		
}
	cout<<sum;
	return 0;
}

/* for(int i=0;i<m;i++){
    	s=arr[i]+s;
	} 
	int z=s/m;
	for(int i=0;i<n;i++){
		if(arr[i]==z){
			i=z;
		}
	}
	int sum=0;
	for(int i=0;i<z;i++){
	  m=m-arr[z]-arr[i];
	}
	
	else{
			if(i<k){
				sum+1;
				break;
			}else{
				break;
			}
		}	if(m=m-(z-arr[i])=0){
			sum=sum+1;
				m=m-(z-arr[i]);
		        sum=sum+1;
		*/
