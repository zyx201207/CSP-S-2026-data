#include<bits/stdc++.h>
using namespace std;
int main(){
	int c=0,t=1,a;
	long long q;
	cin>>c;
	for(int i=0;i<=c;i++){
		cin>>a;
		if(a>=1000){
			cout<<"1000";
		}
		else{
			cout<<"No";
		}
	} 
	cout<<t; 
	if(a==c){
		cout<<t<<endl;
	}
	else{
		if(t==a){
			cout<<c<<endl;
		}
	}
	return 0;
} 
