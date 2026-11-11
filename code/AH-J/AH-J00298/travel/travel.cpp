#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	f1=(s1==t1);
	if(f1){
		if(s2[0]==t2[0] && s2[1]==t2[1])  f2=1;
	}
	if(f2){
		if(s2[2]<='C' && t2[2]<='C')  f3=1;
		if(s2[2]>'C' && t2[2]>'C')  f3=1;
	}
	if(f3){
		if((s2[2]=='A' && t2[2]=='B')||(s2[2]=='B' && t2[2]=='A'))  f4=1;
		if((s2[2]=='B' && t2[2]=='C')||(s2[2]=='C' && t2[2]=='B'))  f4=1;
		if((s2[2]=='D' && t2[2]=='F')||(s2[2]=='F' && t2[2]=='D'))  f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
