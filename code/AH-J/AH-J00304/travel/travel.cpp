/*
CCF将对所有考生程序查重
*/
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool kkksc03(char a,char b){
	if(a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='F')
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<"1";
		if(b[0]!=d[0]||b[1]!=d[1]){
			cout<<"000";
		}else{
			cout<<"1";
			if(!(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D')){
				cout<<"00";
			}else{
				cout<<"1";
				if(kkksc03(b[2],d[2])||kkksc03(d[2],b[2])){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
