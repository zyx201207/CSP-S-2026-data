#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
bool in_left(char ch){
	return ch>='A'&&ch<='C';
}
bool in_right(char ch){
	return ch>='D'&&ch<='F';
}
bool same(char a,char b){
	bool lt=in_left(a)&&in_left(b);
	bool rt=in_right(a)&&in_right(b);
	return lt||rt;
}
bool is_nxt(char a,char b){
	return abs(a-b)==1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string p1=to_string(s1[0]+s1[1]),p2=to_string(s2[0]+s2[1]);
		if(p1==p2){
			cout<<"1";
			if(same(s1[2],s2[2])){
				cout<<"1";
				if(is_nxt(s1[2],s2[2])){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
