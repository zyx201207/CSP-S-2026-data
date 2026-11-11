#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char a=s1[2],b=s2[2];
			if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
				cout<<"1";
				if(abs(a-b)==1||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}/*
02 01A 02 01B

02 01C 02 01A

02 01C 02 01D

02 02B 02 01A

02 01A 03 01A
*/
