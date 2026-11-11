#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		printf("1");
		int a=0,b=0;
		a+=(a2[0]-'0')*10;
		a+=(a2[1]-'0');
		b+=(b2[0]-'0')*10;
		b+=(b2[1]-'0');
		if(a==b){
			printf("1");
			if(a2[2]<='C'&&b2[2]<='C'){
				printf("1");
				if(a2[2]=='A'&&b2[2]=='C'){
					printf("0\n");
				}
				else if(a2[2]=='C'&&b2[2]=='A'){
					printf("0\n");
				}
				else{
					printf("1\n");
				}
			}
			else if(a2[2]>='D'&&b2[2]>='D'){
				printf("11\n");
			}
			else{
				printf("00\n");
			}
		}
		else{
			printf("000\n");
		}
	}
	else{
		printf("0000\n");
	}
	return 0;
}
