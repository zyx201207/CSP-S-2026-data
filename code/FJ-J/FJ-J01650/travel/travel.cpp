#include<bits/stdc++.h>
using namespace std;
char c[3],s[3],cset[5],sset[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",&c,&cset,&s,&sset);
	if(c[0]==s[0]&&c[1]==s[1]){
		printf("1");
	}else printf("0");
	if(c[0]==s[0]&&c[1]==s[1]){
		if(cset[0]==sset[0]&&cset[1]==sset[1]){
			printf("1");
		}else printf("0");
	}else printf("0");
	if(c[0]==s[0]&&c[1]==s[1]){
		if(cset[0]==sset[0]&&cset[1]==sset[1]){
			if(cset[2]<='C'){
				if(sset[2]<='C'){
					printf("1");
				}else printf("0");
			}else{
				if(sset[2]>='C'){
					printf("1");
				}else printf("0");
			}
		}else printf("0");
	}else printf("0");
	if(c[0]==s[0]&&c[1]==s[1]){
		if(cset[0]==sset[0]&&cset[1]==sset[1]){
			if(cset[2]<='C'){
				if(sset[2]<='C'){
					if(sset[2]==cset[2]+1||sset[2]==cset[2]-1){
						printf("1");
					}else printf("0");
				}else printf("0");
			}else{
				if(sset[2]>='C'){
					if(sset[2]==cset[2]+1||sset[2]==cset[2]-1){
						printf("1");
					}else printf("0");
				}else printf("0");
			}
		}else printf("0");	
	}else printf("0");
	return 0;
} 
