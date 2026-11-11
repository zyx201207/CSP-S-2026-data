#include<bits/stdc++.h>
using namespace std;
int c[2],s[2];
char f[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c[0],&s[0],&f[0],&c[1],&s[1],&f[1]);
	if(c[0]==c[1]) {
		printf("1");
		if(s[0]==s[1]){
			printf("1");
			if((f[0]<='C'&&f[1]>='D')||(f[0]>='D'&&f[1]<='C')){
				printf("00");
			}else{
				printf("1");
				if(abs(f[0]-f[1])==1) printf("1");
				else printf("0");
			}
		}else{
			printf("000");
		}
	}
	else {
		printf("0000");
	}
	return 0;
}
