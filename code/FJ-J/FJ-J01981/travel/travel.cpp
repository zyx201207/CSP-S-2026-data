#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) printf("1");
	else{
		printf("0000");
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) printf("1");
	else{
		printf("000");
		return 0;
	}
	
	if((s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)||(s1[2]>=68&&s1[2]<=70 && s2[2]>=68&&s2[2]<=70))//if(s1的第三项为A-C并且s2的第三项为A-C 或者 s1的第三项为D-E并且s2的第三项为D-E)
		printf("1");
	else{
		printf("00");
		return 0;
	}
	
	if(s1[2]>=65&&s1[2]<=67){
		if(s1[2]==65){
			if(s2[2]==66) printf("1");
			else printf("0");
		}
		if(s1[2]==66){
			if(s2[2]==65||s2[2]==67) printf("1");
			else printf("0");
		}
		if(s1[2]==67){
			if(s2[3]==66) printf("1");
			else printf("0");
		}
	}
	if(s1[2]>=68&&s1[2]<=70){
		if((s1[2]==68&&s2[2]==70)||(s1[2]==70&&s2[2]==68)) printf("1");
		else printf("0");
	}
	return 0;//freopen结束前注释要删掉！！！ 并保存！！！ 
}
