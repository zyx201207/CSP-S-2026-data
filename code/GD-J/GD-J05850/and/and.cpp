#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q,k=0;
	cin>>n>>m;
	long long yu[n];
	for(int i=0;i<n;i++){
		cin>>yu[i];
	}
	if(m==2){
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		q=yu[i]&yu[j];
		if(q>k) k=q;
		
	}
	}
}
	else{
		for(int i=0;i<n;i++){
		for(int o=i+1;o<n;o++){
			
		for(int j=o+1;j<n;j++){
		q=yu[i]&yu[j]&yu[o];
		if(q>k) k=q;
		
	}
	}
}
	}
	cout<<k;
	
	
	              
                                          	
               	                              
}             
