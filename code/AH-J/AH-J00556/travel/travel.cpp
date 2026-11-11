#include <iostream>
#include <cstdio>
using namespace std;
string a1,b1,a2,b2;
bool check(char x,char y){
	if(x=='A'||x=='B'||x=='C'){
		if(y=='A'||y=='B'||y=='C') return true;
		return false;
	}
	if(y=='D'||y=='E') return true;
	return false;
}
bool check1(char x,char y){
	if((x=='D'&&y=='C')||(x=='C'&&y=='D')) return false;
	if(x-y==1||x-y==-1) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		cout<<1;
		if(b1[0]*10+b1[1]==b2[0]*10+b2[1]){
			cout<<1;
			if(check(b1[2],b2[2])){
				cout<<1;
				if(check1(b1[2],b2[2])){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	} else cout<<"0000";
	
	return 0;
}
