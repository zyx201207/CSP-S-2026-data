#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,a,b;
char seat1,seat2;
bool flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);		
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++){
		a = s1[0] + s1[1];
		seat1 = s1[2];
	}
	for(int i=0;i<3;i++){
		b = s2[0] + s2[1];
		seat2 = s2[2];
	}
	if(c1 == c2){
		flag1 = 1;
	if(a == b){
		flag2 = 1;
	if(seat1 - '0' == 17 && seat2 - '0' == 18){
		flag3 = 1;
		flag4 = 1;
	}
	if(seat1 - '0' == 17 && seat2 - '0' == 19){
		flag3 = 1;
		flag4 = 0; 
	}
	if(seat1 - '0' == 17 && seat2 - '0' == 20){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 17 && seat2 - '0' == 21){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 18 && seat2 - '0' == 17){
		flag3 = 1;
		flag4 = 1; 
	}
	if(seat1 - '0' == 18 && seat2 - '0' == 19){
		flag3 = 1;
		flag4 = 1; 
	}	
	if(seat1 - '0' == 18 && seat2 - '0' == 20){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 18 && seat2 - '0' == 21){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 19 && seat2 - '0' == 17){
		flag3 = 1;
		flag4 = 0; 
	}
	if(seat1 - '0' == 19 && seat2 - '0' == 18){
		flag3 = 1;
		flag4 = 1; 
	}
	if(seat1 - '0' == 19 && seat2 - '0' == 20){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 19 && seat2 - '0' == 21){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 20 && seat2 - '0' == 17){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 20 && seat2 - '0' == 18){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 20 && seat2 - '0' == 19){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 20 && seat2 - '0' == 21){
		flag3 = 1;
		flag4 = 1; 
	}
	if(seat1 - '0' == 21 && seat2 - '0' == 17){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 21 && seat2 - '0' == 18){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 21 && seat2 - '0' == 19){
		flag3 = 0;
		flag4 = 0; 
	}
	if(seat1 - '0' == 21 && seat2 - '0' == 20){
		flag3 = 1;
		flag4 = 1; 
	}
}
}
	
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
