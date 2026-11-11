#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int rx,zx,ry,zy;
char rz,zz;
string rw,zw;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> rx >> rw >> zx >> zw;
	ry += rw[0] - 48;
	ry *= 10;
	ry += rw[1] - 48;
	zy += zw[0] - 48;
	zy *= 10;
	zy += zw[1] - 48;
	rz = rw[2];
	zz = zw[2];
	if (rz == 'D') rz++;
	if (zz == 'D') zz++;
	
	if (rx != zx){
		cout << "0000";
		return 0;
	} else {
		cout << "1";
	}
	if (ry != zy){
		cout << "000";
		return 0;
	} else {
		cout << "1";
	}
	if ((rz < 'D' && zz > 'D')|| (rz > 'D' && zz < 'D')){
		cout << "00";
		return 0;
	} else {
		cout << "1";
	}
	int rc = rz - 64;
	int zc = zz - 64;
 	if (rc - zc == 1 || rc - zc == -1){
		cout << "1";
	} else {
		cout << "0";
	}
}
