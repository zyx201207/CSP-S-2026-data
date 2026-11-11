#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&c1);
	cin>>s1;
	scanf("%d",&c2);
	cin>>s2;
	if(c1==c2){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	if(a==b){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		printf("1");
	}else{
		printf("0");
		return 0;
	}
	return 0;
} 
