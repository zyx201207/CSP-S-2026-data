#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	bool fang,pai,ce,lin;
	cin >> c1>>s1>>c2>>s2;
	fang= (c1==c2);
	if(fang)cout << '1';
	else cout << '0';
	pai = s1[0]==s2[0] && s1[1]==s2[1];
	if(pai && fang)cout <<'1';
	else cout <<'0';
	ce=((s1[2]>='D' && s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'));
	if(fang && pai &&ce)cout <<'1';
	else cout <<'0';
	int nu=abs(s1[2]-s2[2]);
	lin=((s1[2]>='D' && s2[2]>='D')||(nu<2));
	if(fang && pai &&ce&&lin)cout <<'1';
	else cout <<'0';
	return 0;
}
