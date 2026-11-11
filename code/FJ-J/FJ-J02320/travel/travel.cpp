#include <iostream>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,t=0;
	char e,f;
	std::cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		std::cout<<"1";
		if(b==d){
			std::cout<<"1";
			if((e<='C'&&f<='C')||(e>'C'&&f>'C')){
				std::cout<<"1";
				if(e-f==1||e-f==-1){std::cout<<"1";}else{std::cout<<"0";}
			}else{
			std::cout<<"0";
			if(e-f==1||e-f==-1){std::cout<<"1";}else{std::cout<<"0";}
			}
		}else{std::cout<<"000";}
	}else{std::cout<<"0000";}
	return 0;
}

