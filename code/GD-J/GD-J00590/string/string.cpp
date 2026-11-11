#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	int a,b,num=0;
	cin>>a>>b>>c;
	num+=b;
	for(int i=1;i<a;i++){
		cin>>b>>c;
		num+=b;	
	} 
	cout<<num/2;
	return 0;
}
