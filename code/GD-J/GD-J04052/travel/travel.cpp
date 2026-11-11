#include <bits/stdc++.h>
using namespace std;
int main(){
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
	}else{
		printf("1");
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			printf("1");
			if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
				printf("1");
				if(s1[2]==s2[2]-1 || s1[2]==s2[2]+1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
			return 0;
		}
		
	}
}