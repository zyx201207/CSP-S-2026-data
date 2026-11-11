#include<bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char ist;
	scanf("%s",c1 + 1);
	scanf("%c",ist);
	scanf("%s",s1 + 1);
	scanf("%c",ist);
	scanf("%s",c2 + 1);
	scanf("%c",ist);
	scanf("%s",s2 + 1);
	bool x = true;
	for(int i = 1;i <= 2;i++){
		if(c1[i] != c2[i]){
			x = false;
		}
	}
	if(x == false){
		printf("0000");
		return 0;
	}
	x = true;
	for(int i = 1;i <= 2;i++){
		if(s1[i] != s2[i]){
			x = false;
		}
	}
	if(x == false){
		printf("1000");
		return 0;
	}
	if(s1[3] <= 'C' && s2[3] <= 'C'){
		if(s1[3] == s2[3] + 1 || s2[3] == s1[3] + 1){
			printf("1111");
			return 0;
		}else{
			printf("1110");
			return 0;		
		}
	}else{
		if(s1[3] >= 'D' && s2[3] >= 'D'){
			printf("1111");
			return 0;
		} else{
			printf("1100");
			return 0;
		}
	}
}
