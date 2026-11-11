#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
int main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2) cout << '1';
	else cout << '0';
	p1=s1[0]+s1[1],p2=s2[0]+s2[1];
	if(c1==c2&&p1==p2) cout << '1';
	else cout << '0';
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&c1==c2&&p1==p2) cout << '1';
	else cout << '0';
	if(s1[2]=='D'||s1[2]=='F'||s2[2]=='D'||s2[2]=='F'){
		if((abs(s1[2]-s2[2])==2)&&(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&c1==c2&&p1==p2)) cout << '1';
		else cout << '0';
		return 0;
	}
	if(abs(int(s1[2]-s2[2]))==1&&(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&c1==c2&&p1==p2)) cout << '1';
	else cout << '0';
	

	return 0;
}
