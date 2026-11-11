#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int tfa=0,tfb=0,tfc=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2){cout << 1;tfa=1;}
	else cout << 0;
	if (s1[0]==s2[0] && s1[1]==s2[1] && tfa){cout << 1;tfb=1;}
	else cout << 0;
	if (((s1[2]-64<=3 && s2[2]-64<=3) || (s1[2]-64>=4 && s2[2]-64>=4)) && tfb){cout << 1;tfc=1;}
	else cout << 0;
	if ((abs(s1[2]-s2[2])==1 && tfc) || ((s1[2]-64==4 || s1[2]-64==6) && tfc)) cout << 1;
	else cout << 0;
	return 0;
}
