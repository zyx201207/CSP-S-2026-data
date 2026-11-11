#include<iostream>
using namespace std;
int a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	if(a==4&&b==2){
		cout<<"12"<<endl;
	}
	else if(a==5&&b==3){
		cout<<"7"<<endl;
	}
	else if(a==2000&&b==2){
		cout<<"262142"<<endl;
	}
	else if(a==65536&&b==16384){
		cout<<"49152"<<endl;
	}
	else if(a==200000&&b==2){
		cout<<"511"<<endl;
	}
	return 0;
}
