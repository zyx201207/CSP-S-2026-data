#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ca >> sa >> cb >> sb;
	x = (sa[0] - '0') * 10 + (sa[1] - '0');
	y = (sb[0] - '0') * 10 + (sb[1] - '0');
	if(ca == cb){
		cout << 1;
	}
	else cout << 0;
	if(ca == cb){
		if(x == y) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	if(ca == cb){
		if(x == y){
			if((sa[2] <= 'C' && sb[2] <= 'C') || (sa[2] > 'C' && sb[2] > 'C')) cout << 1;
			else cout << 0;
		}
		else cout << 0;
	}
	else cout << 0;
	if(ca == cb){
		if(x == y){
			if((sa[2] <= 'C' && sb[2] <= 'C') || (sa[2] > 'C' && sb[2] > 'C')){
				if(max(sa[2],sb[2]) - min(sa[2],sb[2]) == 1) cout << 1;
				else cout << 0;
			}
			else cout << 0;
		}
		else cout << 0;
	}
	else cout << 0;
	return 0;
}
