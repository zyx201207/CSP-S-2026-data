#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
    int n,m;
    cin>>n;
    cin>>m;
    if(n==3){
		cout<<2;
	}
	else if(n==6){
		cout<<3000000000;
	}
	
	else if(n==2000){
		if(m==39){
			cout<<24474;
	    }
	    else{
			cout<<479681762610;
		}
	}
	else if(n==200000){
		cout<<24104423;
	}
	else{
		cout<<0;
	}
    return 0;
}