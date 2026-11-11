#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int R,X;
	string r,x;
	cin >> R >> r >> X>> x;
	if(R==X) cout << 1;
	else cout << 0;
	if ((R==X)&&(r[0]==x[0]&&r[1]==x[1]))cout << 1;
	else cout << 0;
	bool bol = ((r[2] == 'A'||r[2] == 'B'||r[2] == 'C')&&(x[2] == 'A'||x[2] == 'B'||x[2] == 'C'))||((r[2] == 'D'||r[2] == 'F')&&(x[2] == 'D'||x[2] == 'F'));
	bool bl = ((R==X)&&(r[0]==x[0]&&r[1]==x[1]))&&bol;
	if (bl)cout << 1;
	else cout << 0;
	bool b = (r[2]=='A'&&x[2]=='B')||(r[2]=='B'&&x[2]=='C')||(r[2]=='D'&&x[2]=='F')||(r[2]=='B'&&x[2]=='A')||(r[2]=='C'&&x[2]=='B')||(r[2]=='F'&&x[2]=='D');
	if (bl&&b)cout << 1;
	else cout << 0;
	return 0;
} 
