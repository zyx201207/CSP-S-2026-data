#include <bits/stdc++.h>
using namespace std;
string xr,xx,zr,zx;
bool a1,a2,a3,a4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xr>>zr>>xx>>zx;
	if (xr==xx) {
		a1=1;	
	} 
	else {
		if (zr[0]==zx[0]&&zr[1]==zx[1]&&(zr[2]-1==zx[2]||zx[2]-1==zr[2])) {
			cout<<"0001";
		}
		else {
			cout<<"0000";
		}
		return 0;
	}
	if (zr[0]==zx[0]&&zr[1]==zx[1]) {
		a2=1;
		if ((zr[2]>='A'&&zr[2]<='C'&&zx[2]>='A'&&zx[2]<='C')||(zr[2]>='D'&&zr[2]<='F'&&zx[2]>='D'&&zx[2]<='F')) {
			a3=1;
		} 
	}
	if (a2==1&&a3==1&&(zr[2]-1==zx[2]||zx[2]-1==zr[2])) {
		a4=1;
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
