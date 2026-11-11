#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string r,x;
	cin >> cr >> r >> cx >> x;
	if(cr==cx)cout<< "1";
	else {
		cout<< "0000";
		return 0;
	}
	if(r[1]==x[1]&&r[0]==r[0])cout << "1";
	else {
		cout<< "000";
		return 0;
	}
	if ((r[2]=='A'&&(x[2]=='B'||x[2]=='C'))
	||(r[2]=='B'&&(x[2]=='A'||x[2]=='C'))
	||(r[2]=='C'&&(x[2]=='B'||x[2]=='A'))
	||(r[2]=='D'&&x[2]=='F')
	||(r[2]=='F'&&x[2]=='D'))cout << "1";
	else {	
		cout << "00";
		return 0;
	}
	if((r[2]=='A'&&x[2]=='B')||
	(r[2]=='B'&&x[2]=='A')||
	(r[2]=='B'&&x[2]=='C')||
	(r[2]=='C'&&x[2]=='B')||
	(r[2]=='D'&&x[2]=='F')||
	(r[2]=='F'&&x[2]=='D'))cout<< "1";
	else cout << "0";
	return 0;
	}
