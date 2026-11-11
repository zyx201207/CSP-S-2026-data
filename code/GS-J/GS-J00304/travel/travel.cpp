#include<cstdio>
#include<string>
#include<iostream>

 using namespace std;

int c1,c2,cs1,cs2,cz1,cz2;
string s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2){
		printf("0000");
		return 0;
	}
	
	if(s1[0] != s2[0] || s1[1] != s2[1]){
		printf("1000");
		return 0;
	}
	
	cz1 = s1[2] - 'A';
	cz2 = s2[2] - 'A';
	if(s1[2] == 'A'||s1[2] == 'B'||s1[2] == 'C') cs1 = 1;
	else cs1 = 2;
	if(s2[2] == 'A'||s2[2] == 'B'||s2[2] == 'C') cs2 = 1;
	else cs2 = 2;
	if(cs1 == cs2){
		if(cz1 + 1 == cz2 || cz2 + 1 == cz1) printf("1111");
		else printf("1110");
	}
	else printf("1100");
} 
