#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a != c) cout << "0000";
	else if(b[0] != d[0] || b[1] != d[1]) cout << "1000";
	else{
		int x1 = (int)b[2] - '@';
		int x2 = (int)d[2] - '@';
		if(!(x1 <= 3 && x2 <= 3) || (x1 >= 4 && x2 >= 4)) cout << "1100";
		else if((x1 + 1 == x2) || (x2 + 1 == x1)) cout << "1111";
		else cout << "1110";
	}
	return 0;
}
