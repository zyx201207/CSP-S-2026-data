#include <bits/stdc++.h>
using namespace std;
int a1;
string a2;
int b1;
string b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1 == b1) cout<<"1";
	else cout<<"0";
	
	if((a1 == b1) &&a2[0] == b2[0] && a2[1] == b2[1]) cout<<"1";
	else cout<<"0";
	
	if(((a1 == b1) &&a2[0] == b2[0] && a2[1] == b2[1]) && a2[2]<='C' && b2[2]<='C' ||a2[2]>'C' && b2[2]>'C') cout<<"1";
	else cout<<"0";
	
	if((((a1 == b1) &&a2[0] == b2[0] && a2[1] == b2[1]) && a2[2]<='C' && b2[2]<='C' ||a2[2]>'C' && b2[2]>'C') && (a2[2]-b2[2] == 1 || a2[2]-b2[2] == -1) && !(a2[2]=='C' &&b2[2] == 'D') && !(a2[2]=='D' &&b2[2] == 'C')) cout<<"1";
	else cout<<"0";	
	return 0;
}
