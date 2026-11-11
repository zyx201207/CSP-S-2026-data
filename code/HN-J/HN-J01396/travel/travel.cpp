#include<iostream>
using namespace std;
int main () {
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	string r1,x1;
	char x2,r2;
	long long r,x;
	cin>>r1>>r>>r2>>x1>>x>>x2;
	if(r1==x1) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(r==x) {
		cout<<1;
	} else {
		cout<<0;
	}
	char a='A',c='C',d='D',f='F';
	if(r==x) {
		if(r2>=a&&r2<=c&&x2>=a&&x2<=c) {
			cout<<1;
		} else {
			if(r2==d||r2==f) {
				if(x2==d||x2==f) {
					cout<<1;
				}
			} else {
				cout<<0;
			}

		}


	} else {
		cout<<0;
	}
	if(r1==x1&&r==x) {
		if(r2>=a&&r2<=c) {
			if(x2>=a&&x2<=c) {
				if(r2-1==x2||r2+1==x2) {
					cout<<1;
				}
			}
		} else {
			if(r2==d&&x2==f) {
				cout<<1;
			} else {
				if(r2==f&&x2==d) {
					cout<<1;
				} else {
					cout<<0;
				}
			}
		}

	}else{
		cout<<0;
	}
	return 0;
}
