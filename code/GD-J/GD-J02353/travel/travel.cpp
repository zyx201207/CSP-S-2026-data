#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c1,s,s1;
	cin>>c>>c1>>s>>s1;
	if(c==s){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	int csh=(c1[0]-'0')*10+(c1[1]-'0');
	int ssh=(s1[0]-'0')*10+(s1[1]-'0');
	//×ùÎ»ÅÅµÄÊý×Ö
	
	if(csh==ssh){
		cout<<1;
	} 
	else{
		cout<<"000";
		return 0; 
	}
	
	if(   ( (c1[2]=='A'||c1[2]=='B'||c1[2]=='C') && (s1[2]=='A'||s1[2]=='B'||s1[2]=='C') ) || ( (c1[2]=='D'||c1[2]=='F') && (s1[2]=='D'||s1[2]=='F') ) ) {
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	int czhi=c1[2]-'A';
	int szhi=s1[2]-'A';
	if( ( (abs(czhi-szhi)==1) && (czhi<=2&&szhi<=2) ) || ( (szhi==3&&czhi==5)|| (szhi==5&&czhi==3) )){
		cout<<1;
	}
	else{
		cout<<"0";
	}
} 
