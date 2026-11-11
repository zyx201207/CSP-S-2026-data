#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	if (c1 == c2){
		a='1';
	}
	else a='0';
	
	if (a=='0'){
		cout<<"0000";
		return 0;
	} 
	if (s1[0]==s2[0] && s1[1]==s2[1]){
		b='1';
	}
	else b='0';
	
	if (b=='0') c='0';
	else if (s1[2]>='A' && s2[2]>='A' && s1[2]<='C' && s2[2]<='C'){
		c='1';
	}else if (s1[2]>='D' && s2[2]>='D' && s1[2]<='F' && s1[2]<='F'){
		c='1';
	}else c='0';
	
	if (c=='0' || b=='0') d='0';
	else if (((int)s1[2]+1==(int)s2[2]) || ((int)s2[2]+1==(int)s1[2]+1)){
		if (s1[2]>='A' && s2[2]>='A' && s1[2]<='C' && s2[2]<='C'){
			d='1';
		}
	}
	else if (((int)s1[2]+2==(int)s2[2]) || ((int)s2[2]+2==(int)s1[2]+1)){
		if (s1[2]>='D' && s2[2]>='D' && s1[2]<='F' && s2[2]<='F'){
			d='1';
		}
	}
	else d='0';
	cout<<a<<b<<c<<d;
	
	return 0;
}
