#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c2,c4;
	long long c1,c3,b1=0,b2=0,b3=0;
	cin>>c1>>c2>>c3>>c4;
	long long c5=char(c2[0])+char(c2[1])-96,c6=char(c4[0])+char(c4[1])-96;
	long long c7=char(c2[2]),c8=char(c4[2]);
	if(c1==c3){
		cout<<"1";
		b1=1;
	}
	else cout<<"0";
	
	if(c5==c6&&b1==1){
		cout<<"1";
		b2=1;
	}
	else cout<<"0";
	
	if(b2==1){
		if(c7==65&&c8==66||
		   c7==65&&c8==67||
		   c7==66&&c8==67||
		   c7==66&&c8==65||
		   c7==67&&c8==65||
		   c7==67&&c8==66||
		   c7==68&&c8==70||
		   c7==70&&c8==68){
		   		cout<<"1";
		   		b3=1;
		   }
		//else cout<<"0";
	}
	if(b3==0) cout<<"0";
	
	if(b3==1){
		if(c8-c7==1||c8-c7==1) cout<<"1";
	} 
	else cout<<"0";
	return 0;
} 
