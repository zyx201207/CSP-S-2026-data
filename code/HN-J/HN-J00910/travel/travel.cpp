#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string c1,s1,c2,s2,num1,num2;
char char1,char2;
int a[1000];
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['F']=a['D']=1;
	a['C']=a['B']=a['A']=2;
	cin >> c1 >> s1 >> c2 >> s2;
	num1=s1[0]+s1[1];
	num2=s2[0]+s2[1];
	char1=s1[2];
	char2=s2[2];
	if (c1==c2) cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	if (num1==num2) cout << 1;
 	else {
		cout << "000";
		return 0;
	}
	if (a[char1]==a[char2]) cout << 1;
	else {
		cout << "00";
		return 0;
	}
	if (char1+1==char2||char1-1==char2) cout << 1;
	else cout << "0";
	return 0;
}
