#include<bits/stdc++.h>
using namespace std;

string s1,s2,sa,sb;//单纯变量名，无恶意
bool checkthird(char a, char b){
	int at=a-'A';
	int bt=b-'A';
	if((at>=0&&at<=2&&bt>=0&&bt<=2)||(at==3&&bt==4)||(at==4&&bt==3)){
		return true;
	}else{
		return false;
	}
}
bool checkforth(char a, char b){
	int at=a-'A';
	int bt=b-'A';
	if((bt-at)==1||(at-bt)==1){
		if((bt!=2&&at!=3)||(bt!=3&&at!=2)){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>sa>>sb;
	if(s1[0]==sa[0]&&s1[1]==sa[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==sb[0]&&s2[1]==sb[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(checkthird(s2[2],sb[2])){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(checkforth(s2[2],sb[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
