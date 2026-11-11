#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d; 
	if(a==c){
		printf("1");
		if(b[0]==d[0] && b[1]==d[1]){
			printf("1");
			if((b[2]<='C' && d[2]<='C') || (b[2]>'C' && d[2]>'C')){
				printf("1");
				if(abs(b[2]-d[2])==1){
					printf("1");
				}else printf("0");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	
	
	
	
	return 0; 
	
} 
