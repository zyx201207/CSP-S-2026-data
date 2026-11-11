#include<iostream>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string c1,s1,c2,s2;
	std::cin>>c1>>s1>>c2>>s2;
	bool elsd,elst,elsr;
	std::cout<<(elsd=(c1==c2));
	std::cout<<(elst=(elsd&&s1[0]==s2[0]&&s1[1]==s2[1]));
	std::cout<<(elsr=(elst&&((s1[2]<='C'&&s2[2]<='C'))||(s1[2]>='D'&&s2[2]>='D')));
	std::cout<<(elsr&&std::abs(s1[2]-s2[2])==1);
return 0;}
