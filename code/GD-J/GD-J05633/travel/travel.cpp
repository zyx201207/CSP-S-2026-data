#include<bits/stdc++.h>
#define int long long 
using namespace std;
int h(int a){
	if(a<0){
		return a=-1*a;
	}else{
		return a;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[4],s2[4];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
	    printf("1");
    }else{
    	printf("0000");
    	return 0;
	}
	char b1=s1[2],b2=s2[2];
	int num1=(s1[0]-'0')*10+(s1[1])-'0';
	int num2=(s2[0]-'0')*10+(s2[1])-'0';
	if(num1==num2){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if(b1<='C' && b1>='A' && b2<='C' && b2>='A'){
		printf("1");
	}else if(b1=='D' && b1=='F' || b2=='D' && b2=='F'){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if(h((b1-b2))==1 && !((b1=='C' && b2=='D') || (b1=='D' && b1=='C'))){
		printf("1");
	}else{
		printf("0");
	}
	
	
	
	
	return 0;
}
