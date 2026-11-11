#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2;
int num1,num2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>num1>>s1;
	cin>>c2;
	cin>>num2>>s2;
	if(c1==c2){
		printf("1");
		if(num1==num2){
			printf("1");
			if(s1>'C'&&s2>'C'||s1<='C'&&s2<='C'){
				printf("1");
				if(abs(s1-s2)==1) printf("1");
				else printf("0");
			}else printf("00");
		}else printf("000");
	}
	else{
		printf("0000");
	}
	return 0;
} 
