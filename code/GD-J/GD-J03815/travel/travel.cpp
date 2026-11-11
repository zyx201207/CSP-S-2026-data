#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,c4;
	int c1,c3;
	bool tag=1,aktag=1;
	cin>>c1>>c2>>c3>>c4;
	
	if(c1==c3)cout<<1;
	else {tag=0;cout<<0;aktag=0;};
	
	int aside[8]={1,1,1,2,2};
	char tmp1,tmp2;int line1,line2;
	line1=int(c2[0]-'0')*10+int(c2[1]-'0');
	line2=int(c4[0]-'0')*10+int(c4[1]-'0');
	bool tmptag=1;
	if((line1==line2)&&aktag)cout<<1;
	else {
	cout<<0;tag=0;tmptag=0;
	}
	
	tmp1=c2[2];tmp2=c4[2];
	if(tmp1=='F')tmp1='E';
	if(tmp2=='F')tmp2='E';
	
	if(aside[int(tmp1-'A')]==aside[int(tmp2-'A')]&&tmptag&&aktag)cout<<1;
	else {
	cout<<0;tag=0;
	}
	
	if(tag==1&&aktag){
		if(tmp1==tmp2-1||tmp1==tmp2+1)cout<<1;
		else cout<<0;
	}
	else cout<<0;
}
