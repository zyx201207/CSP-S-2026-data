#include <bits/stdc++.h>

using ll = long long ;

std::string c1 , c2 , s1 , s2;

int main(){
	

	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	
	std::cin>>c1>>c2>>s1>>s2;
	
	//Problem 1
	if (c1==s1 and c1!="01" and c1!="17")
		std::cout<<1;
	else{
		std::cout<<"0000";
		return 0;
	}
	
	//Problem 2
	if (c2.substr(0 , 2) == s2.substr(0 , 2))
		std::cout<<1;
	else{
		std::cout<<"000";
		return 0;
	}
	
	//Problem 3;
	if (c2[2]<='C' and s2[2]<='C')
		std::cout<<1;
	else if (c2[2]>='D' and s2[2]>='D')
		std::cout<<1;
	else {
		std::cout<<"00";
		return 0;
	}
	
	//Problem 4
	char c = c2[2];
	char s = s2[2];
	if (c-s==-1 or s-c==1)
		std::cout<<1;
	else {
		std::cout<<0;
	}	
		
	return 0;
	
}