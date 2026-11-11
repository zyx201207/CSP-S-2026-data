#include<iostream>
using namespace std;
int main(){
	char R,R1,X,X1;
	cin>>R>>R1>>X>>X1;
	if(R==01||R==16||X==1||X==16){cout<<0000;
	}
	if(R==X){
		cout<<1;
	}
	else{cout<<0;
	}
	if(R1==X1){
		cout<<1;
	}
	else{cout<<0;
	}
	return 0;
}
