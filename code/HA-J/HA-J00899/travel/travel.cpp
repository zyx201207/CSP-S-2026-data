#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cc1,cc2,ss1,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1==cc2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((ss1[2]<='C'&&ss2[2]<='C')||(ss1[2]>='D'&&ss2[2]<='D')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(char(ss1[2]+1)==char(ss2[2])||char(ss1[2]-1)==char(ss2[2])){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

