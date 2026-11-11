#include<bits/stdc++.h>
using namespace std ;
string c1,s1,c2,s2;
int a,b;
int main(){
	//freopen("travel","r",stdin);
	//freopen("travel.out",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		a=c1[i]-'0'+a*10;
		b=c2[i]-'0'+b*10;
	}
	if(a==b) printf("1");
	else {
		printf("0000") ;
		return 0;
	}
	a=b=0;
	for(int i=0;i<2;i++){
		a=s1[i]-'0'+a*10;
		b=s2[i]-'0'+b*10;
	}
	if(a==b) printf("1");
	else {
		printf("000");
		return 0; 
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) printf("1");
	else {
		printf("00");
		return 0; 
	}
	int x=abs(s1[2]-s2[2]);
	if(x==1) printf("1");
	else printf("0");
	return 0; 
}
