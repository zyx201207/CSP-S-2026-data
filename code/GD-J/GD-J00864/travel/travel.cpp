#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C')return true;
		else return false;
	}
	if(a=='B'){
		if(b=='A'||b=='C')return true;
		else return false;
	}
	if(a=='C'){
		if(b=='B'||b=='A')return true;
		else return false;
	}
	if(a=='D'){
		if(b=='F')return true;
		else return false;
	}
	if(a=='F'){
		if(b=='D')return true;
		else return false;
	}
}
bool check2(char a,char b){
	if(a=='A'){
		if(b=='B')return true;
		else return false;
	}
	if(a=='B'){
		if(b=='A'||b=='C')return true;
		else return false;
	}
	if(a=='C'){
		if(b=='B')return true;
		else return false;
	}
	if(a=='D'){
		if(b=='F')return true;
		else return false;
	}
	if(a=='F'){
		if(b=='D')return true;
		else return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string pai1,pai2;
	pai1=(s1[0]+s1[1]);//排号 
	pai2=(s2[0]+s2[1]);//排号 
	char a=s1[2],b=s2[2];//ABCDF
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		cout<<"1";
		if(pai1==pai2){
			cout<<"1";
			if(check1(a,b)){//位于同一侧 
				cout<<"1";
				if(check2(a,b)){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else{
			cout<<"000";
		}
	}
} 
/*
02 01A 02 01B

1111

02 01C 02 01A

1110

02 01C 02 01D

1100

02 02B 02 01A

1000

02 01A 03 01A

0000

03 04A 08 02A

0000

03 03A 03 05A
*/
