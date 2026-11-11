#include <iostream>
#include <cmath>
using namespace std;
string srb,src,sxb,sxc;
int rb,rcp,rcz,xb,xcp,xcz;
bool pd() {
	if(rcz>=1&&rcz<=3&&xcz>=1&&xcz<=3) {
		if(abs(rcz-xcz)==1) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
	return false;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>srb>>src>>sxb>>sxc;
	rb=(srb[0]-'0')*10+srb[1]-'0';
	rcp=(src[0]-'0')*10+src[1]-'0';
	rcz=src[2]-'A'+1;
	xb=(sxb[0]-'0')*10+sxb[1]-'0';
	xcp=(sxc[0]-'0')*10+sxc[1]-'0';
	xcz=sxc[2]-'A'+1;
	if(rb==xb) {
		cout<<1;
		if(rcp==xcp) {
			cout<<1;
			if(rcz>=1&&rcz<=3&&xcz>=1&&xcz<=3||(rcz==4||rcz==6)&&(xcz==4||xcz==6)) {
				cout<<1;
				if(pd()) {
					cout<<1;
				}
				else {
					cout<<0;
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
