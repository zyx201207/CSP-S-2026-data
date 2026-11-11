#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	bool a = 0, b = 0, c = 0, d = 0;
	int aa = 0, bb = 0, cc = 0, dd = 0;
	char c1, c2;
	for(int i=0;i<a1.size();i++){
		aa *= 10;
		aa += (a1[i] - '0');
	}
	for(int i=0;i<a2.size()-1;i++){
		bb *= 10;
		bb += (a2[i] - '0');
	}
	for(int i=0;i<b1.size();i++){
		cc *= 10;
		cc += (b1[i] - '0');
	}
	for(int i=0;i<b2.size()-1;i++){
		dd *= 10;
		dd += (b2[i] - '0');
	}
	c1 = a2[a2.size()-1];
	c2 = b2[b2.size()-1];
	if(aa == cc){
		a = 1;
	}
	if(!a){
		cout << "0000";
		return 0;
	}
	if(bb == dd){
		b = 1;
	}
	if(!b){
		cout << "1000";
		return 0;
	}
	if((c1 <= 'C' && c2 <= 'C') || (c1 > 'C' && c2 > 'C')){
		c = 1;
	}
	if(!c){
		cout << "1100";
		return 0;
	}
	int ans = c1;
	int cnt = c2;
	if(ans - 1 == cnt || ans + 1 == cnt){
		d = 1;
	}
	cout << a << b << c << d;
	return 0;
}
