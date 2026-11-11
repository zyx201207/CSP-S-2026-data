#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a1,b1;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		printf("1");
			
		int a3=(a2[0]-48)*10+(a2[1]-48),b3=(b2[0]-48)*10+(b2[1]-48);
		if(a3==b3){
			printf("1");
			
			if((a2[2]>='A' && a2[2]<='C' && b2[2]>='A' && b2[2]<='C') || (a2[2]>='D' && a2[2]<='E' && b2[2]>='D' && b2[2]<='E')){
				printf("1");
				
				if(abs(a2[2]-b2[2])==1) printf("1");
				else printf("0");
			}else printf("00");
			
		}else printf("000");
		
	}else printf("0000");
	
	return 0;
}
