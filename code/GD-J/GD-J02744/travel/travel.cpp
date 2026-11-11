#include <bits/stdc++.h>
using namespace std;

struct p{
	int cx;
	string w;
	int pa;
	char we;
}r,x;
int n=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r.cx >> r.w;
	r.pa=(int)r.w[0]*10+(int)r.w[1];
	r.we=r.w[2];
	cin >> x.cx >> x.w;
	x.pa=(int)x.w[0]*10+(int)x.w[1];
	x.we=x.w[2];
	if(r.cx==x.cx){
		cout << 1;
		n=1;
	}
	else{
		cout << 0;
		n=0;
	}
	if(n==1&&r.pa==x.pa){
		cout << 1;
		n=1;
	}
	else{
		cout << 0;
		n=0;
	}
	if(n==1&&(r.we>='A'&&r.we<='C'&&x.we>='A'&&x.we<='C')||(r.we=='D'&&r.we=='F'&&x.we=='D'&&x.we=='F')){
		cout << 1;
		n=1;
	}
	else{
		cout << 0;
		n=0;
	}
	if(n==1&&(r.we==x.we-1||r.we==x.we+1)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
