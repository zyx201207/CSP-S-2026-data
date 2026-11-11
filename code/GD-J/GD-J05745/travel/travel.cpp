#include<iostream>
int main(){
	int a,b,c,d;
	char a1,a2;
	std::cin>>a>>b>>a1>>c>>d>>a2;
	if(a==c){
	std::cout<<"1";
	if(b==d){
	std::cout<<"1";
	if((a1>'C'&&a2>'C')||(a1<='C'&&a2<='C')){
		std::cout<<"1";
		if((a1>'C'&&a2>'C')||(a1-a2==1||a2-a1==1))std::cout<<"1";
	else std::cout<<"0";
	}
	else {
	std::cout<<"00";
	}
	}else {
	std::cout<<"000";
	}
	}
	else{
	 std::cout<<"0000";
	}
}
