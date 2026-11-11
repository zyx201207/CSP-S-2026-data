#include<bits/stdc++.h>
#define int long long
std::string s1,s2;
bool chk(char a,char b){
	if(a>b)std::swap(a,b);
	if(a+1==b||(a=='D'&&b=='F'))return true;
	return false;
}
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	std::cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		std::cout<<"0000\n";
		return 0;
	}else{
		int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
		char z1=s1[2],z2=s2[2];
//		std::cout<<"p1:"<<p1<<'\n'<<"p2:"<<p2<<'\n'<<"z1:"<<z1<<'\n'<<"z2:"<<z2<<'\n';
		if(p1!=p2){
			std::cout<<"1000\n";
			return 0;
		}else{
			if((z1<='C'&&z2<='C')||(z1>='D'&&z2>='D')){
				if(chk(z1,z2)){
					std::cout<<"1111\n";
					return 0;
				}else{
					std::cout<<"1110\n";
					return 0;
				}
			}else{
				std::cout<<"1100\n";
				return 0;
			}
		}
	}
	return 0;
}
