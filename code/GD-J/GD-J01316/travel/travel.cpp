#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1, s2;
int c1, c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			char x = s1[2], y = s2[2];
			if(x > y) swap(x, y);
			if(x == 'A' && y == 'B' || x == 'B' && y == 'C' || x == 'A' && y == 'C' || x == 'D' && y == 'F'){
				cout << 1;
				if(x == 'A' && y == 'C') cout << 0;
				else cout << 1;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}

