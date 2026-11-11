#include <iostream>
#include <cmath>
using namespace std;

int rcx,rzwn,xcx,xzwn;
char rzwa,xzwa;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rcx>>rzwn>>rzwa>>xcx>>xzwn>>xzwa;
	if (rcx!=xcx) {
		cout<<"0000"<<endl;
	} else {
		cout<<1;
		if (rzwn!=xzwn) {
			cout<<"000"<<endl;
		} else {
			cout<<1;
			if (rzwa<='C') {
				if (xzwa>'C') {
					cout<<"00"<<endl;
				} else {
					cout<<1;
					if (abs((rzwa-'A')-(xzwa-'A'))<=1) {
						cout<<1<<endl;
					} else {
						cout<<0<<endl;
					}
				}
			} else {
				if (xzwa<='C') {
					cout<<"00"<<endl;
				} else {
					cout<<1;
					if (abs((rzwa-'A')-(xzwa-'A'))<=1) {
						cout<<1<<endl;
					} else {
						cout<<0<<endl;
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
