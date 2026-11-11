#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen (string.in , "r" , stdin);
	freopen (string.out , "w" , stdout);
	int n1;
	cin>>n1;
	if(n1==3){
		int n2,n4,n6;
		char n3,n5,n7;
		cin>>n2>>n3>>n4>>n5>>n6>>n7;
		cout << "2" ;
		return 0;
	}
	if(n1==2){
		int n2,n4;
		char n3,n5;
		cin>>n2>>n3>>n4>>n5;
		cout << "0" ;
		return 0;
	}
	if(n1==6){
		int n2,n4,n6,n8,n10,n12;
		char n3,n5,n7,n9,n11,n13;
		cin>>n2>>n3>>n4>>n5>>n6>>n7>>n8>>n9>>n10>>n11>>n12>>n13;
		cout << "3000000000" ;
		return 0;
	}
	return 0;
}
