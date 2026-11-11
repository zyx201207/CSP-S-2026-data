#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ra,rb;
	char rc;
	int xa,xb;
	char xc;
	cin>>ra>>rb>>rc>>xa>>xb>>xc;
	cout<<(ra==xa);
	cout<<(rb==xb);
	if(rc>='D' && xc>='D'){
		cout<< (ra==xa && rb==xb);
		cout<< ((ra==xa && rb==xb)&& ( abs(rc-xc)<=1));
	}
	else if(rc<='C' && xc<='C'){
		cout<< (ra==xa && rb==xb);
		cout<<((ra==xa && rb==xb)&& ( abs(rc-xc)<=1));
	}
	else cout<<0<<0;
	return 0;
}
