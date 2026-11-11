#include<bits/stdc++.h>
using namespace std;
int a,b; 
char c;
string a1,b1,a2,b2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] && a2[1]==b2[1]) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	a=int(a2[2])-64;
	b=int(b2[2])-64;
	if((a>=1 && a<=3 && b>=1 && b<=3) || (a>=4 && a<=5 && b>=4 && b<=5)) cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1) cout<<"1";
	else cout<<"0";
	return 0;
}
