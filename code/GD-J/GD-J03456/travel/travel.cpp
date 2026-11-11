#include<bits/stdc++.h>
using namespace std;
string cr,cx;
string sr,sx;
bool gd(char z){
	if(z>='A'&&z<='C') return false;
	else return true;
}
bool xl(char a,char b){
	if(a>b) swap(a,b);
	return a+1==b;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		printf("1");
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			printf("1");
			if(gd(sr[2])==gd(sx[2])){
				printf("1");
				if(xl(sr[2],sx[2])){
					printf("1");
				}else printf("0");
			}else printf("00");
		}else printf("000");
	}else{
		printf("0000");
	}
	return 0;
}
