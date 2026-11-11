#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
long long a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travelout","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	a=((int)(a2[0])-48)*10+((int)(a2[1])-48);
	b=((int)(b2[0])-48)*10+((int)(b2[1])-48);
	if(a==b){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	c=(int)(a2[2]-64);
	d=(int)(b2[2]-64);
	if((c<=3 && d<=3) || (c>=4 && c<=5 && d>=4 && d<=5)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(c-d)==1){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
