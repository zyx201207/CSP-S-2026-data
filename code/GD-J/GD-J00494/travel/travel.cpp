#include<bits/stdc++.h>
using namespace std;
string x,y,xn,yn,ans="0000";
bool f = 0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>xn>>yn;
	if(x == xn) ans[0] = '1';
	string a = y, b = yn;
	a.erase(2,1);
	b.erase(2,1);
	if(x == xn && a == b){
		f = 1;
		ans[1] = '1';
	}
	string aa="0",bb="0";
	aa = y[2];
	bb = yn[2];
	int an = 0,bn = 0;
	if(f) {
		an = aa[0] - 'A' + 1;
		bn = bb[0] - 'A' + 1;
		if(an <= 3 && bn <= 3) ans[2] = '1';
		else if(an >= 4 && bn >= 4) ans[2] = '1';
		else f = 0;
	}
	if(f) {
		if(an > bn) {
			if(an - 1 == bn) ans[3] = '1';
		}
		else {
			if(bn-1 == an) ans[3] = '1';
		}
	}
	cout<<ans;
	return 0;
} 
