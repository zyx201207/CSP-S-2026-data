#include<bits/stdc++.h>
using namespace;
int c1,c2;
char s1,s2;
bool p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//1
		std::cout<<"1";
		if(s1[3]=="A"||s1[3]=="B"||s1[3]=="C"){//3
			p1 = 1;
		}
		else{
			p1 = 0;
		}
		if(s2[3]=="A"||s2[3]=="B"||s2[3]=="C"){
			p2 = 1;
		}
		else{
			p2 = 0;
		}
		if(s1[1]==s2[1]&&s1[2]==s2[2]){//2
			std::cout<<"1";
			if(p1==p2){
				std::cout<<"1";
				if(s1[3]=="B"||s2[3]=="B"){
					std::cout<<"1"
				}
				else if(p1==0){
					std::cout<<1;
				}
				else{
					std::cout<<"0";
				}
			}
		}
		else{
			std::cout<<"00";
		}
	}
	else{
		std::cout<<"0";
	}


	
	return 0;
}