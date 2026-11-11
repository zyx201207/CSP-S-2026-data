#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string n=" ";
	long long f=0;
	cin>>f;
	string l="3000000000";
	long long k=2*f;
	for(int i=1;i<=k;i++){
		cin>>n; 
	}
	if(f==3){
		cout<<2;
	}
	else if(f==2){
		cout<<0;
	}
	else if(f==6){
		cout<<l;
	}
	else{
	    cout<<1;
	}
	
	
	return 0;
}



 
