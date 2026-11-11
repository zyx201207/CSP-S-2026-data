#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	int a,b;string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		printf("%s","1");
		if(a1[0]==b1[0] && a1[1]==b1[1]){
			printf("%s","1");
			if((a1[2]<='C' && b1[2]<='C')||(a1[2]>'C' && b1[2]>'C')){
				printf("%s","1");
				if(abs(a1[2]-b1[2])==1){
					printf("%s","1");
				}else {
					printf("%s","0");
				}
				
			}else{
				printf("%s","0");
	
			}
		}else {
			printf("%s","000");
			
		}
	}else {
	printf("%s","0000");

	}
	
	return 0;	
} 	
