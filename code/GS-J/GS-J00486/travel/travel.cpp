#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 20;
string s1[maxn];
string s2[maxn];
string w[18];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a = "A";
	string b = "B";
	string c = "C";
	string d = "D";
	string f = "F";
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1==s2){
		cout<<"1";
		
	}else if(s1<=s2){
		cout<<"11";
	}else{
		cout<<"10";
	}
	if(s1 == a||s2 == b){
		cout<<"1";
	}else if(s1==c||s2==b){
		cout<<"1";
	}else if(s1 == d||s2 == f){
		cout<<"1";
	}else{
		cout<<"1";
	}
	return 0;
}
