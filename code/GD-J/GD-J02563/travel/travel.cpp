#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (c1==c2);
	cout << (c1==c2&&s1.substr(0,2)==s2.substr(0,2));
	cout << (c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')));
	cout << (c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&(abs(s1[2]-s2[2])==1));
	return 0;
}

