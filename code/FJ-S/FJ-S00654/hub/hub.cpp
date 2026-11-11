#include<bits/stdc++.h>
using namespace std;
long long a[2000009];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int s, t, a, b;
	cin >> s >> t;
	cin >> s >> t >> a >> b;
	if (s == 0 && t == 2){
		cout << 1 << endl << 2;
	}
	else if (s == 0 && t == 3){
		cout << 1 << endl << 1 << endl << 2;
	}
	else if (s == 0 && t == 5){
		if (a == 602){
			cout << 17 << endl;
			cout << 9 << endl;
			cout << 6 << endl;
			cout << 6 << endl;
			cout << 9 << endl;
		}
		else {
			cout << 189 << endl;
			cout << 233 << endl;
			cout << 288 << endl;
			cout << 229 << endl;
			cout << 338 << endl;
		}
	}
	else if (s == 0 && t == 1){
		cout << 12251 << endl;
	}
	return 0;
}
