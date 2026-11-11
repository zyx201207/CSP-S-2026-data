#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q;
	long long s=0;
	cin>>q;
	long long n[q+1]={0};
	char m[q+10]={0};     
	 long long num=0;   
	long long h=0;                                        
	
	for(int i=0;i<q;i++){
		cin>>n[i];           
		cin>>m[i];
		s=s+n[i];
	}               
	char kk[s+10]={0};   
	for(int i=0;i<q;i++){
		for(int j=0;j<n[i];j++){
		kk[h]=m[i];
		
		h+=1;
		
	}
			
	}
	for(int i=0;i<s/2+s%2;i++){
		if(kk[i]!=kk[s-i-1]){
			num+=1;
		}
		
	}
	cout<<num;
	
                                          	
               	                              
}             
