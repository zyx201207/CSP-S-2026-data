#include<bits/stdc++.h>
using namespace std;
string ci1,si1,ci2,si2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ci1>>si1>>ci2>>si2;
	if(ci1==ci2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0<<endl;
		return 0;
	}
	int to=si1[0]*10+si1[1]-'0';
	int te=si2[0]*10+si2[1]-'0';
	if(to==te){
		cout<<1;
	}else{
		cout<<0<<0<<0<<endl;
		return 0;
	}
	if((si1[2]=='A'||si1[2]=='B'||si1[2]=='C')&&(si2[2]=='A'||si2[2]=='B'||si2[2]=='C')){
		cout<<1;
	}else if((si1[2]=='D'||si1[2]=='F')&&(si2[2]=='D'||si2[2]=='F')){
		cout<<1;
	}else{
		cout<<0<<0<<endl;
		return 0;
	}
	if((si1[2]=='D'&&si2[2]=='F')||(si2[2]=='D'&&si1[2]=='F')){
		cout<<1;
	}else if(((si1[2]=='A'&&si2[2]=='B')||(si1[2]=='B'&&si2[2]=='A'))||
	((si1[2]=='B'&&si2[2]=='C')||(si1[2]=='B'&&si2[2]=='C'))){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
