#include <bits/stdc++.h>
using namespace std;
string sr,sx;
int cr,cx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	//1
	if(cr==cx) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	//2
	if(sr[0]==sx[0] && sr[1]==sx[1]) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	//3
	char r=sr[2];
	char x=sx[2];
	if((r=='A'||r=='B'||r=='C')&&(x=='A'||x=='B'||x=='C')) cout<<"1";
	else if((r=='D'||r=='F')&&(x=='D'||x=='F')) cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	//4
	int m=r-'A';
	int n=x-'A';
	if(abs(m-n)==1) cout<<"1";
	else {
		cout<<"0";
		return 0;
	}
	return 0;
}
