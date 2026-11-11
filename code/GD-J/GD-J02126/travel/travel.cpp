#include<bits/stdc++.h>
std::string c_1,s_1,c_2,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trvel.out","w",stdout);
	std::cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2) {
		std::cout<<'1';
		if(s_1[0]==s_2[0] && s_1[1]==s_2[1]){
			std::cout<<'1';
			if(s_1[2]>='A' && s_1[2]<='C'){
				if(s_2[2]>='A' && s_2[2]<='C'){
					std::cout<<'1';
					if((s_1[2]=='A'&&s_2[2]=='B')||(s_1[2]=='B'&&s_2[2]=='C') ||(s_2[2]=='A'&&s_1[2]=='B')||(s_2[2]=='B'&&s_1[2]=='C')) std::cout<<'1';
					else std::cout<<'0';
				}
				else std::cout<<'0'<<'0';
			}
			else if(s_1[2]=='D' || s_1[2]=='F'){
				if(s_2[2]=='D' || s_2[2]=='F'){
					std::cout<<'1'<<'1';
				}
				else std::cout<<'0'<<'0';
			}
		}
		else std::cout<<'0'<<'0'<<'0';
	}
	else std::cout<<'0'<<'0'<<'0'<<'0';
	return 0;
}
