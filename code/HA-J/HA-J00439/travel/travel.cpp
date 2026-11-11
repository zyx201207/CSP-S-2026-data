#include<iostream>
#include<string>
using namespace std;
string ac,az,bc,bz;
struct u{
	int che,pai,zuo;
}a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ac >> az >> bc >> bz;
	a.che = (ac[0] - '0') * 10 + ac[1] - '0';
	a.pai = (az[0] - '0') * 10 + az[1] - '0';
	a.zuo = az[2] - 'A' + 1 + (az[2] == 'D');
	b.che = (bc[0] - '0') * 10 + bc[1] - '0';
	b.pai = (bz[0] - '0') * 10 + bz[1] - '0';
	b.zuo = bz[2] - 'A' + 1 + (bz[2] == 'D');
	if(a.che == b.che) cout << 1;
	else cout << 0;
	if(a.che == b.che && a.pai == b.pai) cout << 1;
	else cout << 0;
	if(a.che == b.che && a.pai == b.pai && ((a.zuo <= 3 && b.zuo <= 3) || (a.zuo > 3 && b.zuo > 3))) cout << 1;
	else cout << 0;
	if(a.che == b.che && a.pai == b.pai && (a.zuo - b.zuo == 1 || a.zuo - b.zuo == -1)) cout << 1;
	else cout << 0;
	return 0;
}
