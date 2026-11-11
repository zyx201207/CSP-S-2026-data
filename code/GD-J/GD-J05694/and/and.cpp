#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,s=0,k=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		s=a[0];
		for(int i=1;i<n;i++){
			s=s&(a[i]);
		}
	}
	if(m==n-1){
	    for(int i=0;i<n;i++){
		    if(i==0){
		    	k=a[1];
			}else{
				k=a[0];
			}
		    for(int j=0;j<n;j++){
		    	if(j!=i){
		    		k=k&a[j];
				} 
			}
			s=max(s,k);
	    } 
	}
	if(m==n-2){
	    for(int i=0;i<n-1;i++){
	    	for(int z=i+1;z<n;z++){
			if(i==0){
				if(z==1){
				    k=a[1];
				}else{
		    	    k=a[1];
		        }
			}else{
				k=a[0];
			}
		    for(int j=0;j<n;j++){
		    	if(j!=i and j!=z){
		    		k=k&a[j];
				} 
			}
			s=max(s,k);
			}
		    
	    } 
	}
	if(m==1){
		for(int i=0;i<n;i++){
			s=max(s,a[i]);
		}
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
	}
	cout<<s;
	return 0;
}
