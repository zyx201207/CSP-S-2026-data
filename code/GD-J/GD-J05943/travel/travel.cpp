#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char sc1,sc2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>sc1>>c2>>s2>>sc2;
	if(c1==c2){
		printf("1");
		if(s1==s2){
			printf("1");
			if((sc1>='A'&&sc1<='C'&&sc2>='A'&&sc2<='C')||(sc1>'C'&&sc2>'C')){
				printf("1");
				if(sc1=='A'&&sc2=='B'){
					printf("1");
				}
				else if(sc1=='B'&&(sc2=='A'||sc2=='C')){
					printf("1");
				}
				else if(sc1=='C'&&sc2=='B'){
					printf("1");
				}
				else if(sc1=='D'&&sc2=='F'){
					printf("1");
				}
				else if(sc1=='F'&&sc2=='D'){
					printf("1");
				}
				else printf("0");
			}
			else{
				printf("00");
			}
		}
		else{
			printf("000");
		}
	}
	else{
		printf("0000");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
