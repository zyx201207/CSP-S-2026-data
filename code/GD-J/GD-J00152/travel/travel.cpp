#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a >> b >> c >> d;
	int x = 0,y = 0;
	x = a[0] - '0';
	x = x * 10 + a[1] - '0';
	y = c[0] - '0';
	y = y * 10 + c[1] - '0';
	if(x == y){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	x = 0;
	y = 0;
	x = b[0] - '0';
	x = x * 10 + b[1] - '0';
	y = d[0] - '0';
	y = y * 10 + d[1] - '0';
//	cout << x << " " << y << "\n";
	if(x == y){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	x = 0;
	y = 0;
	if(b[2] == 'D' || b[2] == 'F')x = 1;
	if(d[2] == 'D' || d[2] == 'F')y = 1;
	if(x == y){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}
	int p = b[2] - 'A';
	int q = d[2] - 'A';
	if(abs(p - q) == 1){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
