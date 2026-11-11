#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int rng(string &s){
	if(s[2]=='A'||s[2]=='B'||s[2]=='C')return 0;
	return 1;
}
bool ch(char x,char y){
	if(x>y)swap(x,y);
	if(y-x==1||x=='D'&&y=='F')return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else if((s1[0]-48)*10+(s1[1]-48)!=(s2[0]-48)*10+(s2[1]-48))cout<<"1000";
	else if(rng(s1)!=rng(s2))cout<<"1100";
	else if(!ch(s1[2],s2[2]))cout<<"1110";
	else cout<<"1111";
} 
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
