#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1;
	string c2,s2;
	cin >> c1 >> c2 >> s1 >> s2;
	if(c1 == s1){
		cout << 1;
		int v1 = c2[0] + c2[1];
		int v2 = s2[0] + s2[1];
		if(v1 == v2){
			cout << 1;
			char n1 = c2[2];
			char n2 = s2[2];
			if(int(n1) <= int('C') && int(n2) <= int('C')){
				cout << 1;
				if(abs(int(n1) - int(n2)) == 1) cout << 1;
				else cout << 0;
			}
			else if(int(n1) >= int('D') && int(n2) >= int('D')) cout << "11";
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
