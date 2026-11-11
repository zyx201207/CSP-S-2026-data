#include <bits/stdc++.h>

int main(){
	std::freopen("travel.in","r",stdin);
	std::freopen("travel.out","w",stdout);
	std::string c1,s1,c2,s2;
	std::cin>>c1>>s1>>c2>>s2;
	if (c1!=c2){
		std::cout<<"0000"<<std::endl;
		return 0;
	}else if (c1==c2){
		std::cout<<"1";
		if (s1.substr(0,2)==s2.substr(0,2)) std::cout<<"1";
		else{
			std::cout<<"000"<<std::endl;
			return 0;
		}
		if ((s1[2]=='A' && (s2[2]=='B' || s2[2]=='C')) || (s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) || (s1[2]=='C' && (s2[2]=='A' || s2[2]=='B')) || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) std::cout<<"1";
		else{
			std::cout<<"00"<<std::endl;
			return 0;
		}
		if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && (s2[2]=='A' || s2[2]=='C')) || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) std::cout<<"1";
		else std::cout<<"0";
	}
	return 0;
}

