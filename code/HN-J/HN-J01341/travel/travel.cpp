#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a, b, n, m;
	cin >> a >> b >> n >> m;
	if(a == n){
		cout << '1';
	}
	else{
		cout << "0000";
		return 0;
	}
	if(b[0] == m[0]&&b[1] == m[1]){
		cout << '1';
	}
	else{
		cout << "000";
		return 0;
	}
	if((b[2] == 'A'||b[2] == 'B'||b[2] == 'C')&&(m[2] == 'A'||m[2] == 'B'||m[2] == 'C')||(b[2] == 'D'||b[2] == 'F'&&m[2] == 'D'||m[2] == 'F')){
		cout << '1';
	}
	else{
		cout << "00";
		return 0;
	}
	if(b[2] - m[2] == 1||m[2] - b[2] == 1){
		cout <<'1';
	}
	else{
		cout <<'0';
	}
	return 0;
}
