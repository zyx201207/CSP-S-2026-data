#include<bits/stdc++.h>
using namespace std;
int n,s=1,a[1000000];
long long int k;
char b[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];		
	}
	for(int i=1;i<=n/2+1;i++){
		if(b[i]==b[n-i+1]){	
		k=1;		
		}
		else{
			k=0;
			break;
		}
    }
    if(k){
    	cout<<"0";
	} 
	else{
		for(int i=1;i<=n/2;i++){
		    if(b[i]!=b[n-i+1]){	
		        k=k+a[i];
    	    }
       }
       cout<<k;
	}
}
