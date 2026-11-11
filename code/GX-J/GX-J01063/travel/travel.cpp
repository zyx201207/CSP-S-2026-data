#include<bits/stdc++.h>
using namespace std;
#define int long long
string reads(){
	string t="";
	char ch=getchar();
	while(ch<' ')ch=getchar();
	while(ch>' '){
		t+=ch;
		ch=getchar();
	}
	return t;
}
int val(char x){
	if(x=='A')return 1;
	if(x=='B')return 2;
	if(x=='C')return 3;
	if(x=='D')return 4;
	return 5;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1=reads(),a2=reads(),b1=reads(),b2=reads();
	if(a1==b1)printf("1");
	else{
		printf("0000\n");
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		printf("1");
	}
	else{
		printf("000\n");
		return 0;
	}
	char x=a2[2],y=b2[2];
	int a=val(x),b=val(y);
	if((a<=3&&b<=3)||(a>=4&&b>=4)){
		printf("1");
	}
	else{
		printf("00\n");
		return 0;
	}
	if((a==3&&b==4)||(a==4&&b==3)){
		printf("0\n");
		return 0;
	}
	if(abs(a-b)==1){
		printf("1\n");
	}
	else printf("0\n");
	return 0;
}
