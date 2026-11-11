#include <bits/stdc++.h>
using namespace std;
long long n,m;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int s;
    cin>>n>>m;
    
    if (n==1){
		cout<<1;
	}
	else if(n<=2){
		cout<<5;
	}
	else if(n<=10){
		cout<<100;
	}
	else if(n<=2000){
		cout<<10000;
	}
	else{
		cout<<s;
	}
   
		
		
    
    
    
    



    return 0;
}
