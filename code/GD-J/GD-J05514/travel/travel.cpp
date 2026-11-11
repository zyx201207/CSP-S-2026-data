#include <bits/stdc++.h>
using namespace std;
int t[2];
string a[2];
bool u;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> t[0] >> a[0] >> t[1] >> a[1];
	if (t[0] == t[1]){
		u = true;
		cout << 1;
	}else{
		cout << 0;
	}
	if (u&&a[0][0] == a[1][0]&&a[0][1] == a[1][1]){
		cout << 1;
	}else{
		u = false;
		cout << 0;
	}
	if (u&&((a[0][2] <= 'C') == (a[1][2] <= 'C'))){
		cout << 1;
	}else{
		u = false;
		cout << 0;
	}
	if (u&&(a[0][2]-a[1][2] == 1||a[1][2]-a[0][2] == 1)){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
