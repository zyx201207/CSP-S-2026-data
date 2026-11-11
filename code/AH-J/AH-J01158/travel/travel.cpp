#include <bits/stdc++.h>
using namespace std;
int a1[10];
string b1,c1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trvel.out","w",stdout);
	cin>>a1[0]>>b1>>a1[1]>>c1;
	if(a1[0]!=a1[1]){
		cout<<0000;
	}else if((b1[0]*10+b1[1])!=(c1[0]*10+c1[1])){
		cout<<1000;
	}else if(((b1[2]=A&&b1[2]=B&&b1[2]=C)&&(c1[2]=D&&c1[2]=F))||((c1[2]=A&&c1[2]=B&&c1[2]=C)&&(b1[2]=D&&b1[2]=F))){
		cout<<1100;
	}else if(b1[2]=A&&c1[2]=C){
		cout<<1110;
	}else{
		cout<<1111;
	}
	return 0;
} 
