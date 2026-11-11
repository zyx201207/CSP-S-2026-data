#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std ;
int main(){
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	string c1 , c2 , c3 , c4 ;
	cin >> c1 >> c2 >> c3 >> c4 ;
	if(c1 == c3){printf("1");}
	else{printf("0");}
	if(c1 == c3 && c2[0] == c4[0] && c2[1] == c4[1]){
		printf("1") ;
		if(c2[2]<='C'&&c4[2]<='C' || c2[2]>='D'&&c4[2]>='D'){
			printf("1") ;
			if(abs(c2[2]-c4[2])==1){
				printf("1") ;
			}else{
				printf("0") ;
			}
		}else{
			printf("00") ;
		}
	}else{
		printf("000") ;
	}
	printf("\n") ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}