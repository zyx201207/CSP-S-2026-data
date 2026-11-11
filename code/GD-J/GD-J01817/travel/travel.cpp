#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check1(char c){
	if(c=='A' || c=='B' || c=='C') return 1;
	else return 0;
}
bool check2(char c){
	if(c=='E' || c=='F') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string t1="  ",t2="  ";
	char ch1,ch2;
	t1[0]=s1[0],t1[1]=s1[1],ch1=s1[2];
	t2[0]=s2[0],t2[1]=s2[1],ch2=s2[2];
	if(c1==c2) cout << 1;
	else{
		cout <<"0000";
		return 0;
	}
	
	if(t1==t2) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if(check1(ch1) && check1(ch2) || check2(ch1) && check2(ch2)) cout << 1;
	else{
		cout <<"00";
		return 0;
	}
	if(ch1=='A' && ch2=='C' || ch1=='C' && ch2=='A') cout <<0;
	else cout << 1;
	return 0;
}
