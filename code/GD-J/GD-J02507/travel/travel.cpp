#include<bits/stdc++.h>
using namespace std;
int r,x,rr,xx;
char s,rrr,xxx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	while((s=getchar())!=' '){
		r*=10;
		r+=(s-'0');
	}
	while((s=getchar())!=' '){
		if(s>='A'&&s<='F'){
			rrr=s;
		}else{
			rr*=10;
			rr+=(s-'0');
		}
	}
	while((s=getchar())!=' '){
		x*=10;
		x+=(s-'0');
	}
	while((s=getchar())!='\n'){
		if(s>='A'&&s<='F'){
			xxx=s;
		}else{
			xx*=10;
			xx+=(s-'0');
		}
	}
	if(x==r){
		printf("1");
		if(xx==rr){
			printf("1");
			if(xxx>='D'&&rrr>='D'){
				printf("1");
				if((xxx=='D'&&rrr=='F')||(xxx=='F'&&rrr=='D')){
					printf("1\n");
				}else{
					printf("0\n");
				}
			}else if(xxx<='C'&&rrr<='C'){
				printf("1");
				if((xxx-rrr==1)||(rrr-xxx==1)){
					printf("1\n");
				}else{
					printf("0\n");
				}
			}else{
				printf("00\n");
			}
		}else{
			printf("000\n");
		}
	}else{
		printf("0000\n");
	}
	return 0;
}
