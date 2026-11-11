#include <bits/stdc++.h>
using namespace std;
int rnum,xnum,rright,xright,p,q;
string rset,xset;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rnum>>rset>>xnum>>xset;
	if(rset[2]=='D' or rset[2]=='F') rright==1;
	else rright==0;
	if(xset[2]=='D' or xset[2]=='F') xright==1;
	else xright==0;
	if(rset[2]=='A') p=1;
	if(rset[2]=='B') p=2;
	if(rset[2]=='C') p=3;
	if(xset[2]=='A') q=1;
	if(xset[2]=='B') q=2;
	if(xset[2]=='C') q=3;
	if(rnum==xnum){
		cout<<"1";
		if(rset[0]==xset[0] and rset[1]==xset[1]){
			cout<<"1";
			if(rright==xright){
				cout<<"1";
				if(rright==1||p-q==1||q-p==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
