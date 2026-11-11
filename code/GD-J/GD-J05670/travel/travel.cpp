#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
struct{
	int pt;
	string s;
	bool side;
}r, x;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r.pt >> r.s >> x.pt >> x.s;
	if(r.s[2] =='D' || r.s[2] == 'F'){
		r.side = 1;
	}
	if(x.s[2] =='D' || x.s[2] == 'F'){
		x.side = 1;
	}
	if(r.pt != x.pt){
		cout << "0000";
		return 0;
	}
	
	else{
		a = 1;
		if(r.s[0] == x.s[0] && r.s[1] == x.s[1]){
			b = 1;
		}
		else{
			cout << "1000";
			return 0;
		}
		if(r.side == x.side){
			c = 1;
			if((r.s[2] == x.s[2] + 1 || x.s[2] == r.s[2] + 1) || (r.s[2] == 'D' && x.s[2] == 'F') || (x.s[2] == 'D' && r.s[2] == 'F')){
				d = 1;
			}
		}
		
	}
	cout << a << b << c << d;
	
	
	
	
	return 0;
} 
