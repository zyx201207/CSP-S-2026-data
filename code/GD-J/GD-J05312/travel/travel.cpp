#include<bits/stdc++.h>
std::string c1,s1,c2,s2;
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	std::cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			if(!((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))){
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					std::cout<<"1110";
				}else{
					std::cout<<"1111";
				}
			}else{
				std::cout<<"1100";
			}
		}else{
			std::cout<<"1000";
		}
	}else{
		std::cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
