#include<bits/stdc++.h>
using namespace std;
int rl,xl;
int rh,xh;
char rw,xw;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rl>>rh>>rw>>xl>>xh>>xw;
	if(rl!=xl){
		cout<<"0000";
		return 0;
	}
	if(rh!=xh){
		cout<<"1000";
		return 0;
	}
	if(((rw>='A'&&rw<='C')&&(xw>='A'&&xw<='C'))||((rw>='D'&&rw<='F')&&(xw>='D'&&xw<='F'))){
		if(abs(rw-xw)==1||(rw=='D'&&xw=='F'||rw=='F'&&xw=='D')){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1100";
	return 0;
 } 
