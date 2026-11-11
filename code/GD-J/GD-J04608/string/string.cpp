#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
    
	int n;
	long long a,s=0;
	char c,z;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
	}
	for(int i=0;i<n;i++){
		s=s+a;
		}	
	
		
			
	
    if(n=1){
    	cout<<"0";
	}
	if(s%2==1){
		cout<<s/2+1;
	}else cout<<s/2;
	
	
	return 0;
}
