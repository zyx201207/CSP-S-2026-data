#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;



int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		printf("1");
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				printf("1");
				if (abs(s1[2]-s2[2])==1){
					printf("1");
				}
				else{
					printf("0");
				}
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
	printf("\n");
	
	
	return 0;
	
}
/*
02 01A 02 01B

*/

/*
02 01C 02 01A

*/

/*
02 01C 02 01D
*/
