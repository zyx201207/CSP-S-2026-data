#include <bits/stdc++.h>

std::string a1,a2,a3,a4;
std::string s1,ss1,s2,ss2;

int main(){
	std::frepoen("travel.in","r",stdin);
	std::freopen("travel.out","w",stdout);
	
	std::cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		std::cout<<1;
		}
	else{
		std::cout<<0;
	}
	int su1=0,su2=0;
	for(int i=0;i<=1;i++)
	{
			s1+=a2[i];
			su1+=int(a2[i]);
			s2+=a4[i];
			su2+=int (a4[i]);
			
	}
	ss1=a2[2];
	ss2=a4[2];
	int p=ss1[0];
	int p2=ss2[0];
	if(s1==s2){
		std::cout<<1;
		}
	else{
		std::cout<<0;	
	}
	if(s1==s2){
		if(p-p2==1||p-p2==-1){
			std::cout<<1;
		}
	}
	else{
		std::cout<<0;
		
	}
	if(ss1=="C"&&ss2=="D"||ss2=="C"&&ss1=="D"){
		std::cout<<0;
	
	}
	else if(ss1==ss2){
		if(su1-su2==1||su1-su2==-1){
			std::cout<<1;
		}
	}
	else if(s1==s2){
		if(p-p2==1||p-p2==-1){
			std::cout<<1;
		}
	}		
	else{
		std::cout<<0;
	}
		
		
		
		return 0;
}
