#include <bits/stdc++.h>
using namespace std;
#define int long long
string cx,sx,cy,sy;
bool check(string a,string b){
	for(int i = 0;i <= 1;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}
bool ce(string a,string b){
	if(a[2] == 'A'){
		if(b[2] == 'B' || b[2] == 'C') return true;
		return false;
	}
	if(a[2] == 'B'){
		if(b[2] == 'A' || b[2] == 'C') return true;
		return false;
	}
	if(a[2] == 'C'){
		if(b[2] == 'A' || b[2] == 'B') return true;
		return false;
	}
	if(a[2] == 'D'){
		if(b[2] == 'F') return true;
		return false;
	}
	if(a[2] == 'F'){
		if(b[2] == 'D') return true;
		return false;
	}
}
bool near(string a,string b){
	if(a[2] == 'A'){
		if(b[2] == 'B') return true;
		return false;
	}
	if(a[2] == 'B'){
		if(b[2] == 'A' || b[2] == 'C') return true;
		return false;
	}
	if(a[2] == 'C'){
		if(b[2] == 'B') return true;
		return false;
	}
	if(a[2] == 'D'){
		if(b[2] == 'F') return true;
		return false;
	}
	if(a[2] == 'F'){
		if(b[2] == 'D') return true;
		return false;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cx >> sx >> cy >> sy;
	if(cx == cy){
		cout << "1";
		if(check(sx,sy)){//ее 
			cout << "1";
			if(ce(sx,sy)){//╡Ю 
				cout << "1";
				if(near(sx,sy)) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
