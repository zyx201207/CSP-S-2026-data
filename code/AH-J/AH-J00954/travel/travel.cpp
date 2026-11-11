#include<iostream>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
const string adsg="travel";
bool side(string a){
	switch(a[2]){
	case 'A':return 0;
	case 'B':return 0;
	case 'C':return 0;
	case 'D':return 1;
	case 'E':return 1;
	}return 0;
}
int main(){
	freopen((adsg+".in").c_str(),"r",stdin);
	freopen((adsg+".out").c_str(),"w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){cout<<"0000";return 0;}
	cout<<1;
	if(a2.substr(0,2)!=b2.substr(0,2)){cout<<"000";return 0;}
	cout<<1;
	if(side(a2)!=side(b2)){cout<<"00";return 0;}
	cout<<1;
	if(a2[2]==b2[2]-1||a2[2]-1==b2[2]){cout<<"1";return 0;}
	cout<<0;
	//done
}
