#include"bits/stdc++.h"
using namespace std;
map<char,int>mp;
int f(string s){
	return (s[0]-'0')*10+s[1]-'0'; 
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cc1=f(c1),cc2=f(c2);
	int ss1=f(s1),ss2=f(s2);
	char s_1=s1[2],s_2=s2[2];
	if(cc1!=cc2){
		puts("0000");
		return 0;
	}
	printf("1");
	if(ss1!=ss2){
		puts("000");
		return 0;
	}
	printf("1");
	if(mp[s_1]!=mp[s_2]){
		puts("00");
		return 0;
	}
	printf("1");
	if(mp[s_1]==2){
		puts("1");
		return 0;
	}
	if(abs(s_1-s_2)==1){
		puts("1");
		return 0;
	}
	puts("0"); 
	return 0;
} 
//AH-J01680
//8:30-12:00
