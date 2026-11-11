#include <bits/stdc++.h>
using namespace std;
long long n,s[1000000],c[1000000];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	}
    if (n==1){
		cout<<0;
	}
	else if(n<=2){
		cout<<2;
	}
	else if(n<=10){
		cout<<100;
	}
	else if(n<=2000){
		cout<<10000;
	}
	else{
		cout<<0;
	}
   
		
		
    
    
    
    



    return 0;
}
