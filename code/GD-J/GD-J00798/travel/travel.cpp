#include <bits/stdc++.h>
using namespace std;\
int calc(char c){
	return c-'A'+1;
}
void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string str1,str2;
	str1+=s1[0],str1+=s1[1],str2+=s2[0],str2+=s2[1];
	char ch1=s1[2],ch2=s2[2];
	bool f=1;
	if(c1!=c2) f=0;
	if(!f) cout<<0;
	else cout<<1;
	if(str1!=str2 or !f) f=0;
	if(!f) cout<<0;
	else cout<<1;
	if(calc(ch1)<=3 and calc(ch2)>3) f=0;
	else if(calc(ch1)>3 and calc(ch2)<=3) f=0;
	if(!f) cout<<0;
	else cout<<1;
	if(abs(ch1-ch2)!=1) f=0;
	if(!f) cout<<0;
	else cout<<1;
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
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
*/
