#include<bits/stdc++.h>
using namespace std;
char ca[5],cb[5],sa[5],sb[5];
bool check(char a,char b){
	if(abs(a-b)==1){
		if(a=='C'&&b=='D')return 0;
		if(a=='D'&&b=='C')return 0;
		return 1;
	}return 0;
}
bool ch(char a,char b){
	if(a>='A'&&a<='C'&&'A'<=b&&b<='C')return 1;
	if('D'<=a&&a<='F'&&'D'<=b&&b<='F')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb; 
	if(ca[0]==cb[0]&&ca[1]==cb[1]){
		cout<<1;
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			cout<<1;
			if(ch(sa[2],sb[2])){
				cout<<1;
				if(check(sa[2],sb[2]))cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
