#include<bits/stdc++.h>
std::string s;
bool pd1[5][5]={1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1};
bool pd2[5][5]={0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0};
void eggs(int zw1,int zw2,int cx1,int cx2,char zm1,char zm2){
	if(cx1==cx2){
		std::cout<<1;
	}
	else{
		std::cout<<0;
	}
	if(cx1==cx2&&zw1==zw2){
		std::cout<<1;
	}
	else{
		std::cout<<0;
	}	
	if(cx1==cx2&&zw1==zw2&&pd1[zm1-'A'][zm2-'A']){
		std::cout<<1;
	}
	else{
		std::cout<<0;
	}
	if(cx1==cx2&&zw1==zw2&&pd2[zm1-'A'][zm2-'A']){
		std::cout<<1;
	}
	else{
		std::cout<<0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(std::cin,s);
	eggs((int(s[3])-'0')*10+int(s[4])-'0',(int(s[10])-'0')*10+int(s[11])-'0',(int(s[0])-'0')*10+int(s[1])-'0',(int(s[7])-'0')*10+int(s[8])-'0',s[5],s[12]);
} 
