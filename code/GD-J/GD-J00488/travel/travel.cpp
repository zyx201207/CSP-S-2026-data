#include<bits/stdc++.h>
using namespace std;
string a="",b="";
bool check(char x,char y){
	if(x>y)swap(x,y);
	if(x=='A'&&y=='C')return false;
	else return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c,as,bs;
	for(int i=1;i<=5;i++){
		scanf("%c",&c);
		a=a+c;
	}
	scanf("%c ",&as);
	for(int i=1;i<=5;i++){
		scanf("%c",&c);
		b=b+c;
	}
	scanf("%c",&bs);
	if(a[0]!=b[0]||a[1]!=b[1]){
		printf("0000");
		return 0;
	}
	else if(a[3]!=b[3]||a[4]!=b[4]){
		printf("1000");
		return 0;
	}
	else if(as>='A'&&as<='C'&&bs>='A'&&bs<='C'){
		if(check(as,bs)){
			printf("1111");
			return 0;
		}
		else{
			printf("1110");
			return 0;
		}
	}
	else if((as=='D'&&bs=='F')||(as=='F'&&bs=='D')){
		printf("1111");
		return 0;
	}
	else{
		printf("1100");
		return 0;
	}
	return 0;
}
