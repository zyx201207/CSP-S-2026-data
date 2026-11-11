




#include <iostream>

int main(int argc, char **argv)
{
		//freopen("travel.in","r",stdin);
		//freopen("travel.out","w",stdout);
		std::string c1,c2,s1,s2;
		int s=0;
		std::cin>>c1>>c2>>s1>>s2;
		if(c1==c2) std::cout<<"1";
		for(int i=0;i<=1;i++){
			if(s1[i]==s2[i]) s++;
		}
		if(s==2) std::cout<<"1";
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				std::cout<<"1";
		}
		}
		if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F'){
				std::cout<<"1";
		}
		}
		if(s1[2]+1-'A'==s2[2]-'A'||s1[2]-1-'A'==s2[2]-'A') std::cout<<"1";
	return 0;
}

