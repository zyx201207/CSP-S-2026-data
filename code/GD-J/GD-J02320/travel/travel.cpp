#include <iostream>
using namespace std;
int main(){
	fopen("travel.cpp","travel.in");
	fopen("travel.cpp","travel.ans");
	string a,c,b,d,t="1";
	cin>>a;
	cin>>c;
	cin>>b;
	cin>>d;
	if(a[0]==b[0]){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(c[0]==d[0]){
		if(c[1]==d[1]){
			if(d[2]==c[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
